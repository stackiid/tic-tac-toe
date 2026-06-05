# Tic-Tac-Toe Game

> A two-player terminal Tic-Tac-Toe game with score tracking, built in C++ as my first semester project.

---

## 📋 Overview

This was my first structured C++ project, written in Semester 1 while learning the fundamentals of the language. The goal was to build something interactive that put arrays, loops, conditionals, and functions together in a way that actually worked as a real program - not just isolated exercises.

The game runs in the Windows terminal, supports two local players, validates every move, and keeps a running scoreboard across multiple rounds.

---

## ✅ Features

- **Two-player local game** - both players enter their names at the start
- **Score tracking** - wins and draws are counted across multiple rounds
- **Input validation** - rejects out-of-range numbers, already-taken cells, and non-numeric input
- **Play again loop** - players can keep going without restarting the program
- **Clean board display** - screen is cleared before each move for a readable layout

---

## 🧠 Concepts Demonstrated

- 2D arrays (the game board)
- Functions with return values (`playRound()` returns the result)
- Control flow - `while` loops, `if/else`, `continue`, `break`
- `cin` input validation with `numeric_limits` to handle bad input
- Global variables (board and player names shared across functions)
- `char` vs `string` usage for signs and player identifiers

---

## 📁 Project Structure

```
tic-tac-toe/
├── main.cpp        ← Full game logic in a single file
└── README.md
```

---

## 🚀 Getting Started

**Requirements:** A C++ compiler (g++, MinGW, or any IDE like Code::Blocks / VS Code with C++ extension)

**Compile and run:**

```bash
g++ main.cpp -o tictactoe
./tictactoe
```

Or open `main.cpp` in Code::Blocks and hit Run.

---

## 📝 Notes

- Uses `system("cls")` for screen clearing - Windows only. On Linux/macOS, replace with `system("clear")`.
- No AI opponent - strictly two human players.
- Intended as a Semester 1 project; the scope is kept deliberately simple.

---

## 📄 License

MIT - see the [LICENSE](./LICENSE) file in the root of the repository.
