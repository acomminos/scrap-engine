set (SOURCE
    engine.cc
    example_scene.cc
#    model.cc
#    doodad.cc
)

find_package (PkgConfig REQUIRED)
pkg_search_module (GLFW REQUIRED glfw3)
include_directories (${GLFW_INCLUDE_DIRS})

add_library (scrap ${SOURCE})
target_link_libraries (scrap ${GLFW_LIBRARIES})
