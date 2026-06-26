*This project has been created as part of the 42 curriculum by recan.*

# miniRT

## Description

The miniRT project is an introduction to the world of ray-tracing. The goal is to create a realistic 3D image renderer from scratch using the ray-tracing algorithm. By simulating the path of light through a virtual scene, this project demonstrates how to render basic geometric shapes, handle camera perspectives, implement lighting models, and calculate shadows.

This project strengthens your understanding of:

- 3D coordinate systems and vector mathematics (linear algebra)
- The Ray-Tracing algorithm (Ray-Object intersection)
- Camera management and perspective projection
- The Phong reflection model (Ambient, Diffuse, Specular)
- Parsing scene descriptions and scene management
- Memory management in C

The program simulates the rendering of a scene defined in a .rt file, producing a windowed graphical output via the MiniLibX library.

## Mandatory Part

### Program Behavior

The program must behave like:

./miniRT <scene_file.rt>

It renders the scene described in the .rt file into a graphical window. The program must handle basic shapes, camera positioning, and lighting correctly.

### Example

./miniRT scenes/sphere.rt

The application will open a window and display the rendered image based on the provided configuration.

## Allowed Functions

open, close, read, write, printf, malloc, free, perror, strerror, exit

All functions from <math.h>

All functions from <mlx.h>

## Compilation

To compile the mandatory part:

make

This produces the executable: miniRT.

## Usage

./miniRT <path_to_scene.rt>

Example:
./miniRT scenes/basic_scene.rt

## Implementation Overview

### 1. Vector Mathematics
- A dedicated module (vec3.c) handles all 3D operations: addition, subtraction, scaling, dot product, cross product, and normalization.
- This layer forms the backbone of all geometric and light calculations.

### 2. The Rendering Pipeline
- The program iterates through every pixel of the window screen.
- A ray is generated from the camera origin through each pixel into the 3D space.
- The hit_object routine determines if the ray intersects with any scene objects (Sphere, Cylinder, Plane).

### 3. Intersection Logic
- Each primitive shape (Sphere, Cylinder, Plane) implements its own mathematical intersection formula using quadratic equations.
- We resolve the closest t parameter to ensure correct depth ordering.

### 4. Lighting and Shadows
- Ambient Lighting: Provides a baseline illumination for all objects.
- Diffuse Lighting (Lambertian): Calculated using the dot product between the surface normal and the light direction.
- Shadows: A shadow ray is cast from the hit point towards the light source; if it hits another object before reaching the light, the point is obscured.

### 5. Camera Management
- Supports dynamic positioning and orientation.
- Field of View (FOV) and direction vectors allow for flexible camera control within the scene.

### 6. Mathematical Foundations
The core of this engine relies on geometric optics and vector analysis. The following equations are implemented to simulate light transport:

#### 6.1 Ray Equation
A ray is defined by an origin $\mathbf{O}$ and a normalized direction vector $\mathbf{D}$. Any point $\mathbf{P}$ on the ray can be calculated as a function of the scalar $t$ (distance):$$\mathbf{P}(t) = \mathbf{O} + t\mathbf{D}, \quad t > 0$$

#### 6.2 Sphere Intersection
To find the intersection of a ray with a sphere centered at $\mathbf{C}$ with radius $r$, we solve the quadratic equation derived from $\|\mathbf{P}(t) - \mathbf{C}\|^2 = r^2$:$$t^2(\mathbf{D} \cdot \mathbf{D}) + 2t(\mathbf{D} \cdot (\mathbf{O} - \mathbf{C})) + (\mathbf{O} - \mathbf{C}) \cdot (\mathbf{O} - \mathbf{C}) - r^2 = 0$$We solve for $t$ using the quadratic formula, selecting the smallest positive root to determine the closest hit point.

#### 6.3 Lambertian Diffuse Reflection
The brightness of a surface depends on the angle between the surface normal $\mathbf{N}$ and the light direction vector $\mathbf{L}$. Using the dot product of two normalized vectors:$$\text{Intensity} = \max(\mathbf{N} \cdot \mathbf{L}, 0)$$
This ensures that surfaces facing away from the light source receive no direct illumination.

## Error Handling

The program properly handles:

- Invalid file extensions or missing files.
- Malformed .rt file syntax.
- Out-of-bounds coordinate or color values.
- System initialization and MLX allocation failures.
- Memory leaks and resource cleanup upon exit.

## Memory Management

- All heap allocations are tracked and freed using a clean cleanup routine.
- MLX resources (window, image, display) are systematically destroyed.
- No memory leaks occur during normal operation or upon error termination.

## Design Choices

- Modular Architecture: Logic is split into discrete modules (render.c, ray.c, parser.c, etc.) for maintainability.
- Data Structures: Centralized reference structures manage scene objects, lights, and camera properties to avoid global variables.
- Mathematical Precision: Use of double precision throughout the ray-tracing pipeline ensures stable intersection results.

## Why this project matters

miniRT is a foundational project that:

- Introduces the principles of Computer Generated Imagery (CGI).
- Bridges the gap between pure mathematics (linear algebra) and graphical output.
- Provides a deep understanding of how light behaves in a 3D environment.
- Teaches precision in handling complex geometric data structures.

## Resources

- miniRT subject (42 curriculum)
- Ray Tracing in One Weekend (Peter Shirley)
- Linear Algebra for Computer Graphics
- MiniLibX documentation

## AI Usage Disclosure

AI assistance was used only for:

- Structuring and formatting this README
- Improving overall grammar, documentation clarity, and readability
- To create the test sets and clarify the expectations.

AI was not used to implement or debug the philosophers logic.
