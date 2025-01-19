# Ping-Pong-CPP

This repository was used as a study object for the development of a ping-pong game using C++ and Raylib.

## Description

The project consists of a simple ping-pong game where two players control paddles to hit the ball back and forth. The objective is to score points when the ball passes the opponent's paddle.

## Features

- Player 1 paddle control (Up/Down keys)
- CPU paddle control
- Scoring for each player
- Automatic ball reset after scoring
- Game ends when one of the players reaches 5 points

## Technologies Used

- Programming Language: C++
- Graphics Library: Raylib
- Build System: CMake

## How to Run

### Prerequisites

- [CMake](https://cmake.org/)
- [Raylib](https://www.raylib.com/)

### Steps

1. Clone the repository:
   ```sh
   git clone https://github.com/GuilhermeNono/Ping-Pong-CPP.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Ping-Pong-CPP
   ```
3. Create a directory for build files:
   ```sh
   mkdir build
   cd build
   ```
4. Generate build files with CMake:
   ```sh
   cmake ..
   ```
5. Build the project:
   ```sh
   cmake --build .
   ```
6. Run the game:
   ```sh
   ./PingPongGame
   ```

## Contribution

Feel free to contribute with improvements to this project. To do so:
1. Fork this repository.
2. Create a branch for your feature/bugfix:
   ```sh
   git checkout -b my-feature
   ```
3. Commit your changes:
   ```sh
   git commit -m 'Add new feature'
   ```
4. Push to the remote repository:
   ```sh
   git push origin my-feature
   ```
5. Open a Pull Request.

## License

This project is licensed under the [MIT License](LICENSE).

---
