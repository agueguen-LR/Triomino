cmake_minimum_required(VERSION 3.5)

if(POLICY CMP0110)
  cmake_policy(SET CMP0110 NEW)
endif()

project(Triomino C)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

enable_testing()

find_package(CcLint)
enable_cclint()

find_package(FlawFinder)
enable_flaw_finder()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(docs)

set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES "/build/;/.vscode/;/.venv/;/.git/;/.idea/;~$;${CPACK_SOURCE_IGNORE_FILES}")
message(STATUS "CPACK_SOURCE_IGNORE_FILES=${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
