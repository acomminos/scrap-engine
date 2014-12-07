set (SOURCE
    engine.cc
    gl/shader.cc
    gl/program.cc
    texture.cc
    material.cc
    model.cc
    doodad.cc
    scene/model_scene.cc
)

find_package (PkgConfig REQUIRED)
pkg_search_module (GLFW REQUIRED glfw3)
include_directories (${GLFW_INCLUDE_DIRS})

add_definitions(-DGLFW_INCLUDE_ES2)

add_library (scrap ${SOURCE})
target_link_libraries (scrap ${GLFW_LIBRARIES})
