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

#include <unistd.h>
#include <cstdio>
#include <cstdlib>

#include "scrap/engine.h"
#include "scrap/settings.h"
#include "salvage/example_scene.h"

int main(int argc, char *argv[]) {
    scrap::Settings settings;
    int err = 0;
    char arg;
    while ((arg = getopt(argc, argv, ":w:h:f:v")) != -1 && !err) {
        switch (arg) {
            case 'w':
                settings.set_width(atoi(optarg));
                break;
            case 'h':
                settings.set_height(atoi(optarg));
                break;
            case 'f':
                break;
            case 'v':
                break;
            case ':':
                fprintf(stderr, "Option -%c requires an operand\n", optopt);
                err = 1;
                break;
            case '?':
                fprintf(stderr, "Unrecognized option: -%c\n", optopt);
                err = 1;
                break;
        }
    }

    if (err) {
        fprintf(stderr, "Usage: salvage [OPTION]... [FILE]...\n");
        return -1;
    }

    std::string scene;
    if (optind < argc)
        scene = std::string(argv[argc - 1]);
    else
        scene = "default";

    printf("Starting salvage (libscrap sandbox)...\n"
           "Loading scene '%s'\n...", scene.c_str());


    salvage::ExampleScene es;
    scrap::engine::Init(&es, settings);

    return 0;
}
