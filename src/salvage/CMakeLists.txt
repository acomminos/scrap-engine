set (SOURCE
    src/example_scene.cc
    src/main.cc
)

add_executable (salvage ${SOURCE})
target_link_libraries (salvage scrap)
install (TARGETS salvage DESTINATION bin)
install (DIRECTORY share/ DESTINATION share)
