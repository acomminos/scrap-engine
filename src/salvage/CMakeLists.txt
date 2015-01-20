set (SOURCE
    example_scene.cc
    main.cc
)

add_executable (salvage ${SOURCE})
target_link_libraries (salvage scrap)
install (TARGETS salvage DESTINATION bin)
