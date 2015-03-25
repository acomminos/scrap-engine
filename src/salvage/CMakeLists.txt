set (SOURCE
    world.cc
    world_loader.cc
    example_scene.cc
    main.cc
)

find_package (PkgConfig REQUIRED)
pkg_search_module (LIBARCHIVE REQUIRED libarchive)
include_directories (${LIBARCHIVE_INCLUDE_DIRS})

add_executable (salvage ${SOURCE})
target_link_libraries (salvage scrap ${LIBARCHIVE_LIBRARIES})
install (TARGETS salvage DESTINATION bin)
