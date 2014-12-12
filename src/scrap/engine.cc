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

static GLFWwindow* window_;
static std::stack<scrap::Scene*> scene_stack_;

static void Loop();

void scrap::engine::Init(scrap::Scene *scene, const scrap::Settings& settings) {
    scene_stack_.push(scene);

    glfwInit();

    GLFWmonitor *monitor = NULL;
    if (settings.fullscreen())
        monitor = glfwGetPrimaryMonitor();

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
        scene_stack_.top()->OnSizeChange(width, height);
    });

    glfwMakeContextCurrent(window_);
    Loop();
}

void scrap::engine::Destroy() {
    glfwDestroyWindow(window_);
    glfwTerminate();
}

void scrap::engine::Push(scrap::Scene *scene) {
    scene_stack_.push(scene);
}

void scrap::engine::Pop() {
    scene_stack_.pop();
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
