set (SOURCE
    engine.cc
    camera.cc
    gl/shader.cc
    gl/program.cc
    gl/texture.cc
    gl/material.cc
    gl/model.cc
    doodad.cc
    renderer.cc
    scene/model_scene.cc
)

find_package (PkgConfig REQUIRED)
pkg_search_module (GLFW REQUIRED glfw3)
pkg_search_module (CAIRO REQUIRED cairo)
include_directories (${GLFW_INCLUDE_DIRS})
include_directories (${CAIRO_INCLUDE_DIRS})

add_definitions(-DGLFW_INCLUDE_ES2)
add_definitions(-DGLM_FORCE_RADIANS)

add_library (scrap SHARED ${SOURCE})
target_link_libraries (scrap ${GLFW_LIBRARIES} ${CAIRO_LIBRARIES})

install (TARGETS scrap DESTINATION lib)
install (DIRECTORY . DESTINATION include/scrap FILES_MATCHING PATTERN "*.h")
