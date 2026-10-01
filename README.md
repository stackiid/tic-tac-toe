# Tic-Tac-Toe

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C)
![Platform](https://img.shields.io/badge/platform-Windows%20console-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)

A two-player, console-based Tic-Tac-Toe game written in C++ as a Semester 1 project. Two people share one keyboard, take turns choosing board positions, and the program tracks wins and draws across as many rounds as they want to play.

## Features

- Local two-player game with custom player names
- Player 1 plays as `X` and Player 2 plays as `O`; Player 1 moves first in every round
- Numbered board (positions 1-9) redrawn after every move
- Win detection across all rows, columns, and both diagonals
- Draw detection when all nine moves are used without a winner
- Input validation for non-numeric input, out-of-range numbers, and already-taken positions
- Scoreboard (wins per player and draws) shown after each round and again when the game ends
- Play-again loop so multiple rounds can be played in a single session

## Tech Stack

| Category | Details |
| --- | --- |
| Language | C++ |
| Standard library | `<iostream>`, `<string>`, `<limits>` |
| Compiler | Any C++ compiler such as g++ (MinGW on Windows) |

The program has no external dependencies.

## Project Structure

```text
tic-tac-toe/
|-- main.cpp     # Complete game logic in a single source file
|-- LICENSE      # MIT License
`-- README.md
```

## How It Works

All logic lives in `main.cpp`:

| Function | Purpose |
| --- | --- |
| `resetBoard()` | Fills the 3x3 board with the characters `'1'` to `'9'` at the start of each round |
| `showBoard()` | Clears the screen and prints the title, both player names, and the current board |
| `hasWon()` | Checks the three rows, three columns, and two diagonals for three matching cells |
| `playRound()` | Runs one round and returns `1` (Player 1 wins), `2` (Player 2 wins), or `0` (draw) |
| `main()` | Reads player names, loops over rounds, updates the scoreboard, and asks whether to play again |

The board is stored in a global `char board[3][3]`. An unplayed cell holds its position number, and a played cell holds `'X'` or `'O'`. A move is rejected if the chosen cell already contains `'X'` or `'O'`.

Board positions map to the grid as follows:

```text
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
```

## Prerequisites

- A C++ compiler such as g++ (for example, MinGW on Windows)
- A Windows terminal, because the program calls `system("cls")` to clear the screen

## Getting Started

Clone the repository and move into it:

```bash
git clone https://github.com/stackiid/tic-tac-toe.git
cd tic-tac-toe
```

Compile the game:

```bash
g++ main.cpp -o tictactoe
```

Run it:

```bash
# Windows PowerShell
.\tictactoe.exe

# Windows Command Prompt
tictactoe
```

## Usage

1. Start the program and enter a name for Player 1 and Player 2.
2. Press Enter to begin. Player 1 plays as `X` and Player 2 plays as `O`.
3. On your turn, type a position number from 1 to 9 and press Enter.
4. The round ends when a player completes a line or all nine cells are filled.
5. After each round the scoreboard is displayed. Enter `y` or `Y` to play another round; any other character ends the game and shows the final result.

Example of a board in progress:

```text
  +------  TIC-TAC-TOE  ------+
    Alice [X]   vs   Bob [O]

       X | 2 | 3
      ---|---|---
       4 | O | 6
      ---|---|---
       7 | 8 | 9

  Alice [X]  >>  Choose a position (1-9):
```

### Input Handling

| Situation | Behavior |
| --- | --- |
| Non-numeric input | Input is discarded, a "Numbers only" message is shown, and the same player is prompted again after pressing Enter |
| Number outside 1-9 | A "taken or out of range" message is shown and the same player is prompted again after pressing Enter |
| Position already taken | Same message as above; the turn is not consumed |

## Platform Notes

- Screen clearing uses `system("cls")`, which works on Windows only. On Linux or macOS the game still compiles, but the screen is not cleared properly. Replacing `"cls"` with `"clear"` in `main.cpp` (it appears in `showBoard()` and `main()`) is the straightforward fix for those systems.
- There is no AI opponent; the game is strictly for two human players.
- There are no automated tests in the repository.

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

Copyright (c) 2026 Ubaid Ahmad
