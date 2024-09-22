# so_long

**so_long** is a simple 2D arcade game developed in C using the MLX graphical library as part of the 42 School curriculum. The game features basic AI for enemy movement, collision detection, and a simple level design where the player must navigate through obstacles to reach the exit.

## Features

- **2D Graphics**: Rendered using the MLX graphical library.
- **Basic AI**: Enemy movement and simple behavior.
- **Collision Detection**: Player and enemy interaction with the environment.
- **Collectibles**: Collect items while avoiding enemies.
- **Level Design**: Static maps with obstacles and exit points.

## Compilation & Usage

To compile the game:

```bash
make
```

To run the game:

```bash
./so_long [map_file.ber]
```

Example:

```bash
./so_long maps/map_01.ber
```

### Controls

- **Arrow Keys** or **W/A/S/D**: Move up, left, down, right.
- **ESC**: Exit the game.

## Project Structure

- **src/**: Contains the game source code.
- **mlx/**: MLX graphical library files.
- **libft/**: Custom C library used in the project.
- **Makefile**: Used to compile the project.
- **maps/**: Sample map files for the game.
- **assets/**: Sprites used for game characters and objects.

## Requirements

- **MLX Library**: Make sure the MLX library is installed.
- **C Compiler**: Ensure GCC or Clang is available.
- **Make**: The project uses a Makefile for compilation.

## How to Create Maps

Maps are stored as `.ber` files with a simple format:
- **0**: Empty space
- **1**: Wall
- **P**: Player start position
- **E**: Exit
- **C**: Collectible item
- **^, v, >, <**: Enemy

Example:

```
11111
1P0C1
1>001
1C0E1
11111
```

## Learning Objectives

This project was built to strengthen knowledge in:

- 2D game development using low-level C programming.
- Working with a graphical library (MLX).
- Basic AI implementation and collision detection.

---
