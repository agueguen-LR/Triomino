
add_library(triomino SHARED triomino.c triomino.h triomino.inc)

add_executable(triomino-generate triomino-generate.c)
target_link_libraries(triomino-generate triomino)

add_executable(triomino-display triomino-display.c)
target_link_libraries(triomino-display triomino)

install(
  TARGETS triomino triomino-generate triomino-display
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)
install(
    FILES triomino.h
    DESTINATION include
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/triomino.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/triomino.pc
  @ONLY
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/triomino.pc
  DESTINATION share/pkgconfig
  COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/TriominoConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/TriominoConfig.cmake
  INSTALL_DESTINATION cmake
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/TriominoConfig.cmake
  DESTINATION cmake
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()