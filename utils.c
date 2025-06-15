#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "board.h"

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

GameConfig parse_arguments(int argc, char* argv[]) {
    GameConfig config;

    // Default-Werte
    config.board_size = 100;
    config.die_sides = 6;
    config.max_steps = 1000;
    config.simulations = 10000;
    config.num_snakes = 0;
    config.num_ladders = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) {
            config.board_size = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            config.die_sides = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            config.max_steps = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            config.simulations = atoi(argv[++i]);
        }
        else {
            fprintf(stderr, "Unknown or incomplete argument: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    return config;
}
