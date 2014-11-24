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

#ifndef SRC_SCRAP_CONFIG_H_
#define SRC_SCRAP_CONFIG_H_

#include <cstdint>

namespace scrap {

// Configuration options are preferred options for setting up the game engine.
// In the event that an value is unable to be used, the engine is responsible
// for assigning a reasonable value that works.
// TODO(andrew): support for loading from file
class Config {
 public:
  // Creates a new default config with the video mode of the primary monitor.
  Config() : width_(800), height_(600), fullscreen_(false) { }
  uint32_t width() { return width_; }
  void set_width(uint32_t width) { width_ = width; }
  uint32_t height() { return height_; }
  void set_height(uint32_t height) { height_ = height; }
  bool fullscreen() { return fullscreen_; }
  void set_fullscreen(bool fullscreen) { fullscreen_ = fullscreen; }

 private:
  uint32_t width_;
  uint32_t height_;
  bool fullscreen_;
};

};  // namespace scrap

#endif  // SRC_SCRAP_CONFIG_H_
