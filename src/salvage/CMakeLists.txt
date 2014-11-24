set (SOURCE main.cc)

add_executable (salvage ${SOURCE})
target_link_libraries (salvage scrap)
