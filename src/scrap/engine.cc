// Copyright © 2014 Andrew Comminos <andrew@morlunk.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "scrap/engine.h"
#include <cassert>
#include <cstdio>
#include "scrap/gl/gl2ext.h"

static GLFWwindow* window_;
static std::stack<scrap::Scene*> scene_stack_;

static void LoadExtensions();
static void DebugCallback(GLenum source, GLenum type, GLuint id,
                          GLenum severity, GLsizei length,
                          const GLchar *message,
                          const void *userParam);
static void Loop();

void scrap::engine::Init(scrap::Scene *scene, const scrap::Settings& settings) {
    scene_stack_.push(scene);

    glfwInit();

    GLFWmonitor *monitor = NULL;
    if (settings.fullscreen())
        monitor = glfwGetPrimaryMonitor();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE); // for GL_KHR_debug

    window_ = glfwCreateWindow(settings.width(), settings.height(),
                               "Scrap Engine", monitor, NULL);
    if (!window_) {
        glfwTerminate();
        return;
    }
    glfwSetKeyCallback(window_, [](GLFWwindow *, int key, int scancode,
                                   int action, int mods) {
        scene_stack_.top()->OnKey(key, scancode, action, mods);
    });
    glfwSetMouseButtonCallback(window_, [](GLFWwindow *, int button, int action,
                                           int mods) {
        scene_stack_.top()->OnMouseButton(button, action, mods);
    });
    glfwSetFramebufferSizeCallback(window_, [](GLFWwindow*, int width, int height) {
        glViewport(0, 0, width, height); // FIXME(andrew): should this go here?
        scene_stack_.top()->OnSizeChange(width, height);
    });

    glfwMakeContextCurrent(window_);

    LoadExtensions();

    scene->OnShow();
    Loop();
}

void scrap::engine::Destroy() {
    glfwDestroyWindow(window_);
    glfwTerminate();
}

void scrap::engine::Push(scrap::Scene *scene) {
    if (scene_stack_.top())
        scene_stack_.top()->OnHide();
    scene_stack_.push(scene);
    scene->OnShow();
}

void scrap::engine::Pop() {
    assert(scene_stack_.size() > 0);
    scene_stack_.top()->OnHide();
    scene_stack_.pop();
    if (scene_stack_.top()) {
        scene_stack_.top()->OnShow();
    }
    // TODO(andrew): destroy if out of scenes?
    // if (scene_stack_.empty()) {
    //     Destroy();
    // }
}

int scrap::engine::Width() {
    if (window_ == NULL)
        return -1;
    int width;
    glfwGetWindowSize(window_, &width, NULL);
    return width;
}

int scrap::engine::Height() {
    if (window_ == NULL)
        return -1;
    int height;
    glfwGetWindowSize(window_, NULL, &height);
    return height;
}

void LoadExtensions() {
    if (glfwExtensionSupported("GL_KHR_debug")) {
        printf("Enabling GL_KHR_debug logging callback\n");
        glEnable(GL_DEBUG_OUTPUT_KHR);
        PFNGLDEBUGMESSAGECALLBACKKHRPROC glDebugMessageCallbackKHR =
            (PFNGLDEBUGMESSAGECALLBACKKHRPROC)
            glfwGetProcAddress("glDebugMessageCallbackKHR");
        glDebugMessageCallbackKHR([](GLenum source, GLenum type, GLuint id,
                                     GLenum severity, GLsizei length,
                                     const GLchar *message,
                                     const void *userParam) {
            fprintf(stderr, "%s\n", message);
        }, NULL);
    } 
}

void Loop() {
    double delta_time, start_time;
    while (!glfwWindowShouldClose(window_)) {
        start_time = glfwGetTime();

        scrap::Scene *scene = scene_stack_.top();
        scene->Update(delta_time);
        scene->Render();

        glfwSwapBuffers(window_);
        glfwPollEvents();

        delta_time = glfwGetTime() - start_time;
    }
}
