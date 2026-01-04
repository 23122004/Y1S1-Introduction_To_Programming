# GameCaro - Console Gomoku Game

A classic Caro (Gomoku) game implementation in C++ for the Windows Console, featuring Pixel Art graphics, PvP/PvE modes, and game state management.

## 👥 Group 5 - HCMUS - 23TNT1

| Student ID | Name |
| :--- | :--- |
| **23122001** | Dinh Duc Anh Khoa |
| **23122002** | Nguyen Dinh Ha Duong |
| **23122013** | Dinh Duc Tai |
| **23122004** | Nguyen Le Hoang Trung |

**Advisor:** Dr. Truong Toan Thinh

## 🎮 Features

*   **Game Modes**:
    *   **PvP**: Two players play on the same keyboard.
    *   **PvE**: Play against an intelligent Bot (Minimax algorithm).
*   **Game Management**:
    *   **Save Game**: Save your current match state to a file.
    *   **Load Game**: Resume saved matches.
    *   **Undo**: Revert the last move (supports both player and bot turns).
*   **Interface**:
    *   Beautiful Pixel Art graphics rendered in the console.
    *   Interactive Menu System.
    *   Custom board rendering with cursor support.

## 🕹️ Controls

| Action | Player 1 / General | Player 2 |
| :--- | :--- | :--- |
| **Move Up** | `W` | `Up Arrow` |
| **Move Left** | `A` | `Left Arrow` |
| **Move Down** | `S` | `Down Arrow` |
| **Move Right** | `D` | `Right Arrow` |
| **Mark (Select)** | `Space` | `Enter` |
| **Undo** | `U` | |
| **Save Game** | `I` | |
| **Exit** | `Esc` | |

## 📜 Rules

*   **Objective**: Be the first player to form an unbroken line of **5 marks** horizontally, vertically, or diagonally.
*   **Gameplay**:
    *   Players alternate turns placing their marks (X or O) on an empty intersection.
    *   X plays first.
    *   If the board is completely filled and no one has made a line of 5 marks, the game ends in a draw.

## 🛠️ Build & Run

1.  **Requirements**: Windows OS (uses `Windows.h` and `conio.h`), Visual Studio (recommended).
2.  **Open Project**: Open the `GameCaro.sln` file in Visual Studio.
3.  **Build**: Build the solution (Ctrl+Shift+B).
4.  **Run**: Run the application (F5).

## 📂 Project Structure

*   `GameCaro.cpp`: Main entry point.
*   `Menu.cpp/h`: Menu logic and UI.
*   `GameControl.cpp/h`: Core game logic (Minimax, Score evaluation, Board state).
*   `Graphic.cpp/h`: Drawing functions for ASCII/Pixel art.
*   `Console.cpp/h`: Windows Console API wrappers (Colors, Cursor, Window size).
*   `LoadGame.cpp/h`: File I/O for saving and loading games.
*   `Newgame.cpp/h`: New game initialization.
