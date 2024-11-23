include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(Valgrind)


file(GLOB FILES "${CMAKE_SOURCE_DIR}/test/test-*.c")
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

