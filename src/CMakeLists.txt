set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories ("${CMAKE_SOURCE_DIR}/src")
add_subdirectory (scrap)
add_subdirectory (salvage)
