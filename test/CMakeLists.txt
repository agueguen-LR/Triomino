include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(Valgrind)
message(STATUS "VALGRIND_EXECUTABLE=${VALGRIND_EXECUTABLE}")
if(VALGRIND_EXECUTABLE)
  set(VALGRIND ${VALGRIND_EXECUTABLE})
endif()

file(GLOB FILES "${CMAKE_SOURCE_DIR}/test/test-*.c")
message(STATUS "FILES=${FILES}")

foreach(FILENAME ${FILES})
  get_filename_component(SRC ${FILENAME} NAME)
  get_filename_component(TEST ${FILENAME} NAME_WE)
  add_executable(${TEST} ${FILENAME} ${CMAKE_SOURCE_DIR}/src/triomino.h)
  add_dependencies(${TEST} triomino)
  target_link_libraries(${TEST} triomino)
  if(${TEST} STREQUAL "test-generate")
    # Custom command to run triomino-generate and verify output
    add_custom_command(
            OUTPUT test-initial.3
            COMMAND ${CMAKE_COMMAND} -E remove -f test-initial.3
            COMMAND triomino-generate test-initial.3
            DEPENDS triomino-generate
            COMMENT "Running triomino-generate to create test-initial.3"
    )
    add_custom_target(run_triomino_generate ALL DEPENDS test-initial.3)
    if(VALGRIND)
      add_test("${TEST}[normal]" ./test-generate test-initial.3)
      add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./test-generate test-initial.3)
    else()
      add_test("${TEST}" ./test-generate test-initial.3)
    endif()
  else()
    if(VALGRIND)
      add_test("${TEST}[normal]" ./${TEST})
      add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
    else()
      add_test("${TEST}" ./${TEST})
    endif()
  endif()
endforeach()
