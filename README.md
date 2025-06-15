#  Snakes and Ladders Simulator (MCMC)

This project implements a non-interactive simulator for the board game Snakes and Ladders using Markov Chain Monte Carlo (MCMC) methods.

The simulator:

Models the board as a graph of connected nodes (fields).

Simulates a high number of games to calculate statistics.

Supports custom board sizes, snake/ladder setups, and die configurations.

Is fully configurable via command line arguments.

| File        | Description                                                        |
| ----------- | ------------------------------------------------------------------ |
| `main.c`    | Entry point: parses CLI arguments, runs simulation, outputs stats. |
| `game.c/h`  | Simulation logic, statistics calculation, snake/ladder tracking.   |
| `board.c/h` | Board structure, snake/ladder generation, validation.              |
| `utils.c/h` | Utility functions (random number generation, parsing, etc.).       |
| `Makefile`  | Compiles the project with `clang` and strict flags.                |



