set (SOURCE
    engine.cc
    camera.cc
    gl/shader.cc
    gl/program.cc
    gl/texture.cc
    gl/material.cc
    gl/model.cc
    gl/model_renderer.cc
    gl/cairo_renderer.cc
    gl/buffer.cc
    gui/coord.cc
    util/obj_loader.cc
    doodad.cc
    scene/model_scene.cc
)

add_definitions (-DGLFW_INCLUDE_ES2)
add_definitions (-DGLM_FORCE_RADIANS)

find_package (PkgConfig REQUIRED)
pkg_search_module (GLFW REQUIRED glfw3)
pkg_search_module (CAIRO REQUIRED cairo)
include_directories (${GLFW_INCLUDE_DIRS})
include_directories (${CAIRO_INCLUDE_DIRS})

configure_file (config.h.in config.h)

add_library (scrap SHARED ${SOURCE})
target_link_libraries (scrap ${GLFW_LIBRARIES} ${CAIRO_LIBRARIES})

install (TARGETS scrap DESTINATION lib)
install (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/scrap FILES_MATCHING PATTERN "*.h")
