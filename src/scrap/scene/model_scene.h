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

#ifndef SRC_SCRAP_SCENE_MODEL_H_
#define SRC_SCRAP_SCENE_MODEL_H_

#include <vector>
#include <map>
#include <cairo/cairo.h>
#include "scrap/scene.h"
#include "scrap/camera.h"
#include "scrap/doodad.h"
#include "scrap/gl/model_renderer.h"
#include "scrap/gl/program.h"
#include "scrap/gl/model.h"
#include "scrap/gui/cairo_renderer.h"

namespace scrap {

class ModelScene : public Scene {
 public:
  ModelScene();
  ~ModelScene();
  virtual void Render();
  virtual void OnSizeChange(int width, int height);
  virtual void OnShow();
  virtual void OnHide();

  virtual void Update(double delta_time) = 0;
  virtual void DrawGUI(cairo_t *context) = 0;
  virtual void OnMouseButton(int button, int action, int mods) = 0;
  virtual void OnMouseScroll(double dx, double dy) = 0;
  virtual void OnMouseMove(double x, double y) = 0;
  virtual void OnMouseEnter() = 0;
  virtual void OnMouseLeave() = 0;

  virtual void OnKey(int key, int scancode, int action, int mods) = 0;

  const std::vector<Doodad*>& doodads() const { return doodads_; }
  void add_doodad(Doodad *doodad) { doodads_.push_back(doodad); };

  Camera *active_camera() const { return active_camera_; }
  void set_active_camera(Camera *camera) { active_camera_ = camera; }


 private:
  gl::ModelRenderer *model_renderer_;
  gui::CairoRenderer *cairo_renderer_;
  gl::Program default_program_;
  Camera *active_camera_;
  std::vector<Doodad*> doodads_;
};

}  // namespace scrap

#endif  // SRC_SCRAP_SCENE_MODEL_H_
