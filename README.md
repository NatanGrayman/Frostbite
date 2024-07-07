# Project Overview

This project demonstrates the development of a game with multiple features and iterations, following an agile development process over three submissions. The game was built with a strong emphasis on testing and functionality, as well as a user-friendly game console, utilizing SFML for graphics and gameplay.

## Features and Development Phases

### Initial Release

- **Splash Screen**: Implemented a splash screen with game instructions using SFML. The user needs to press Enter to start the game.
- **Character Movement**: The character, Bailey, can move horizontally on ice blocks and jump vertically from each ice block level towards the safe zone. Bailey cannot exceed the game window boundaries.
- **Game Mechanics**: If Bailey contacts the 'water', he dies and returns to the initial position.
- **Testing**: Test cases were implemented to verify the functionality of the game window, player positioning, player movement, ice block movement (including wrapping functionality), and game boundaries.

### Second Release

Building on the first release, the following features were added:

- **Directional Movement**: Bailey changes direction when clicking the left or right key.
- **Scoring System**: Points are added to the total score when Bailey lands on additional ice blocks.
- **Temperature Mechanic**: A countdown timer 'freezes' Bailey if he does not win in time.
- **Lives System**: Bailey has multiple lives, and when all lives are utilized, the splash screen reappears.
- **Enemies**: A row of enemies moving across the screen can push Bailey into the water, killing him.
- **Igloo Building**: An igloo incrementally appears when Bailey lands on additional ice blocks. When the igloo is complete, Bailey can enter the 'door' to win.
- **Level Progression**: Bailey can move to the next level, respawning in the initial position.
- **Testing**: Additional test cases were implemented for each new feature.

### Third Release

The final release introduced a two-player mode with the following enhancements:

- **Two-Player Mode**: A new splash screen indicates the second player mode and the respective keys needed.
- **Second Player Character**: A second character, a red Bailey, spawns in the center.
- **Ice Block Division**: Each ice block is divided into a top and bottom half to show which Bailey has landed.
- **Second Player Igloo**: A new igloo for the second player is displayed incrementally on the left side of the screen.
- **Winning Conditions**: A splash screen appears for the appropriate winning player.
- **Lives Indicator**: '-1' for lives indicates that the player is dead.
- **Additional Testing**: Further testing of key functionality was implemented.
- **Documentation**: Doxygen documentation was implemented for the entire project.

## Demo
[![Demo Video](https://img.youtube.com/vi/OvSKmZw93qI/0.jpg)](https://youtu.be/OvSKmZw93qI?si=aBMRRFjh8WilW2yo)
