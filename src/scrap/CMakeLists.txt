set (SOURCE
    src/engine.cc
    src/camera.cc
    src/gl/shader.cc
    src/gl/program.cc
    src/gl/texture.cc
    src/gl/material.cc
    src/gl/model.cc
    src/doodad.cc
#   src/renderer.cc
    src/scene/model_scene.cc
)

find_package (PkgConfig REQUIRED)
pkg_search_module (GLFW REQUIRED glfw3)
include_directories (${GLFW_INCLUDE_DIRS})

add_definitions(-DGLFW_INCLUDE_ES2)
add_definitions(-DGLM_FORCE_RADIANS)

add_library (scrap SHARED ${SOURCE})
target_link_libraries (scrap ${GLFW_LIBRARIES})

install (TARGETS scrap DESTINATION lib)
install (DIRECTORY src/ DESTINATION include/scrap FILES_MATCHING_PATTERN "*.h")
