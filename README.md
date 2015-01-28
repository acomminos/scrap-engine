Scrap Engine
============

Scrap Engine is a scrappy 3D engine written in C++ using GLFW, GLM, and Cairo.

It is currently very incomplete.

Features
--------

- Simple and readable scene format
- Portable
- Cairo for 2D rendering
- "salvage" scene sandbox

Scene Format
------------

*As follows is a WIP specification for Scrap's scene format. Much is subject to change.*

A scene can be described by a 'junk' directory that may be tarred into '.junk.tar' for distribution.

### Hierarchy

- doodads
    - Contains Doodad files with extension .doodad.json. See [Doodads](#doodad-format).
- models
    - OBJ files referenced by Doodads.
- animations
    - TBD
- textures
    - TBD
- sounds
    - TBD
- shaders
    - Standard GLSL 1.0 vertex and fragment shaders.
    - Can be arbitrarily loaded by scene code.

### Doodad Format

A Doodad is described in JSON for easy version control and human-readability.

Doodad files are stored with the format {{doodad_id}}.doodad.js. The ID used in the name can be used to uniquely identify the Doodad and instantiate it in code.

They may be arbitrarily categorized into subdirectories (i.e. a doodad file named "player.doodad.js" in the subfolder "entities" would be referred to as "entities/player").

#### Example

    {
        "model": "my-model.obj",
        "position": {
            "x": 10.0,
            "y": 10.0,
            "z": 10.0
        },
        "scale": {
            "x": 0.5,
            "y": 0.5,
            "z": 0.5
        },
        "rotation": {
            "x": 0,
            "y": 0,
            "z": 0
        },
        "visible": true,
        "children": [
            "attachments/child-doodad"
        ]
    }
