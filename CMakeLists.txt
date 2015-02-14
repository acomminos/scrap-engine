cmake_minimum_required (VERSION 2.6)
project (scrap)
add_subdirectory (src)
add_subdirectory (test)

install (DIRECTORY share DESTINATION ${CMAKE_INSTALL_PREFIX})
file (COPY share DESTINATION ${CMAKE_BINARY_DIR})
