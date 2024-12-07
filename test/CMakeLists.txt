include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(Valgrind)
message(STATUS "VALGRIND_EXECUTABLE=${VALGRIND_EXECUTABLE}")
if(VALGRIND_EXECUTABLE)
  set(VALGRIND ${VALGRIND_EXECUTABLE})
endif()

add_custom_command(
        OUTPUT test-initial.3
        COMMAND ${CMAKE_COMMAND} -E remove -f test-initial.3
        COMMAND triomino-generate test-initial.3
        DEPENDS triomino-generate
        COMMENT "Running triomino-generate to create test-initial.3"
)
add_custom_target(run_triomino_generate ALL DEPENDS test-initial.3)

file(GLOB FILES "${CMAKE_SOURCE_DIR}/test/lib_tests/test-*.c")
message(STATUS "FILES=${FILES}")

foreach(FILENAME ${FILES})
  get_filename_component(SRC ${FILENAME} NAME)
  get_filename_component(TEST ${FILENAME} NAME_WE)
  add_executable(${TEST} ${FILENAME} ${CMAKE_SOURCE_DIR}/src/triomino.h)
  add_dependencies(${TEST} triomino)
  target_link_libraries(${TEST} triomino)
  if(VALGRIND)
    add_test("${TEST}[normal]" ./${TEST})
    add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
  else()
    add_test("${TEST}" ./${TEST})
  endif()
endforeach()

add_test("test-generate[no_args]" ../src/triomino-generate)
set_property(TEST "test-generate[no_args]" PROPERTY WILL_FAIL TRUE)
add_test("test-generate[override]" ../src/triomino-generate test-initial.3)
set_property(TEST "test-generate[override]" PROPERTY WILL_FAIL TRUE)

add_test("test-display[no_args]" ../src/triomino-display)
set_property(TEST "test-display[no_args]" PROPERTY WILL_FAIL TRUE)
add_test("test-display[no_such_file]" ../src/triomino-display no-file)
set_property(TEST "test-display[no_such_file]" PROPERTY WILL_FAIL TRUE)

add_executable(test-generate test-generate.c)
add_dependencies(test-generate triomino)
target_link_libraries(test-generate triomino)
add_executable(test-display test-display.c)
add_dependencies(test-display triomino)
target_link_libraries(test-display triomino)
if(VALGRIND)
  add_test("test-generate[normal]" ./test-generate test-initial.3)
  add_test("test-generate[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./test-generate test-initial.3)
  add_test("test-display[normal]" ./test-display ../src/triomino-display test-initial.3)
  add_test("test-display[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./test-display ../src/triomino-display test-initial.3)
else()
  add_test("test-generate" ./test-generate test-initial.3)
  add_test("test-display" ./test-display ../src/triomino-display test-initial.3)
endif()