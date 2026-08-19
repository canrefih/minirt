# miniRT

A CPU ray tracer written in C using MiniLibX, built around vector mathematics, ray–object intersection, camera projection, lighting, and shadow computation.

## Engineering Focus

- 3D vector algebra and normalization
- ray generation and camera projection
- sphere, plane, and cylinder intersections
- closest-hit selection
- ambient and diffuse lighting
- shadow rays
- `.rt` scene parsing and validation
- explicit memory and MiniLibX resource management

## Rendering Pipeline

```text
.rt scene
   ↓
parse + validate
   ↓
scene / camera / light state
   ↓
ray generation per pixel
   ↓
ray-object intersection
   ↓
closest hit + surface normal
   ↓
lighting + shadow ray
   ↓
image buffer
   ↓
MiniLibX window
```

## Build & Run

```bash
make
./miniRT scenes/basic_scene.rt
```

The scene file describes the camera, light source, and geometric primitives rendered by the engine.

## Design Notes

The renderer separates vector operations, scene parsing, intersection routines, camera handling, and rendering. Each primitive provides its own intersection logic, while the renderer selects the nearest positive intersection before evaluating lighting.

The core ray equation is:

```text
P(t) = O + tD
```

where `O` is the ray origin and `D` is its normalized direction.

## Error Handling

The parser validates scene syntax, numeric ranges, coordinates, colors, file handling, and initialization failures. Cleanup paths release allocated scene data and MiniLibX resources before termination.

## Development

This project was developed as part of the 42 curriculum. Future changes should use focused branches and validated pull requests into `main`.

## AI Usage

AI assistance was used for documentation structure and clarity only; the renderer implementation was not generated or debugged by AI.
