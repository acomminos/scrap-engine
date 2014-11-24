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

#ifndef SRC_SCRAP_ENGINE_H_
#define SRC_SCRAP_ENGINE_H_

#include <stack>
#include "scrap/config.h"
#include "scrap/scene.h"
#include "scrap/gl/gl_config.h"

// The engine manages the game window and exclusively accesses the GLFW context.
namespace scrap {
namespace engine {

// Initializes the global game engine with the given scene.
void Init(scrap::Scene *scene, scrap::Config config);
// Destroys the engine, freeing all resources.
void Destroy();
// Pushes a new scene onto the engine's scene stack.
void Push(scrap::Scene *scene);
// Pops a scene off of the engine's scene stack.
void Pop();

int Width();
int Height();

}  // namespace engine
}  // namespace scrap

#endif  // SRC_SCRAP_ENGINE_H_
