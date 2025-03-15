# Super Mario Game (SFML)

This project is a Super Mario-inspired game developed using SFML (Simple and Fast Multimedia Library) for C++. The game features custom graphics, audio effects for different collisions, and a main menu, while incorporating gameplay elements and mechanics similar to the classic Super Mario games.

## Features

### 1. **Custom Graphics and Audio**
   - The game includes custom graphics for all entities and backgrounds.
   - Audio effects are implemented for different types of collisions (e.g., player hitting an enemy, player jumping, etc.).
   - Background music plays both in the main menu and during gameplay, enhancing the gaming experience.

### 2. **Entity Hierarchy**
   - **Base Entity:** The `Entity` class represents common entities (player, enemies, objects) in the game.
   - **Player:** The `Player` class extends `Entity` and represents the main character of the game.
   - **Enemies:** The `Enemy` class is a base class for enemies, with specific derivatives like `Goomba` and `Koopa`.
     - **Goomba and Koopa Differences:** When the player jumps on both Goombas and Koopas, they are defeated. However, they take different amounts of damage based on their type, with each enemy having unique damage values to add variety to gameplay.

### 3. **Collision Detection**
   - **Screen Collision:** The player and enemies interact with the screen boundaries, ensuring that they stay within the visible area.
   - **Object Collision:** In addition to screen boundaries, collisions are detected between entities (e.g., player vs. enemies, player vs. objects).
   - **Enemy-Specific Collisions:** Different collision responses are implemented based on the type of enemy (e.g., Goomba, Koopa) to provide unique interactions when the player collides with them.

### 4. **Main Menu**
   - The main menu allows the player to choose between starting the game or quitting.
   - It features a background image, interactive buttons, and plays background music.

# Compilation Instructions

The project is configured with CMake.

## Terminal Instructions:

### Required Libraries on Linux (assuming a Debian-based OS)

```sh
sudo apt-get update && \
  sudo apt-get install libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libdrm-dev \
    libgbm-dev \
    libfreetype6-dev
```

If additional libraries are missing, delete the build folder from step 1 and reconfigure the project after installing the missing dependencies.

### Configuration Step

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

Or on Windows with GCC:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
```

At this step, we can request the generation of project files for various development environments.

### Compilation Step

```sh
cmake --build build --config Debug --parallel 6
```

The `parallel` option specifies the number of files compiled in parallel.

### Installation Step (Optional)

```sh
cmake --install build --config Debug --prefix install_dir
```


### 5. **Audio Integration**
   - The game includes background music that plays in both the main menu and during gameplay.
   - Different audio effects are played depending on the type of collision, such as when the player jumps on an enemy, collects a coin, or hits an object.
