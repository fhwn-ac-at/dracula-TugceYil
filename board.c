#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "utils.h"

static int is_conflict(Jump* jumps, int count, int start, int end) {
    for (int i = 0; i < count; ++i) {
        if (jumps[i].start == start || jumps[i].end == end ||
            jumps[i].start == end || jumps[i].end == start) {
            return 1;
        }
    }
    return 0;
}

void generate_snakes_and_ladders(GameConfig* config) {
    int board_end = config->board_size - 1;

    config->num_snakes = 2;
    config->num_ladders = 2;

    int count = 0;
    while (count < config->num_snakes) {
        int head = rand_int(config->board_size / 2, board_end - 1);
        int tail = rand_int(1, head - 1);
        if (head == board_end) continue;

        if (!is_conflict(config->snakes, count, head, tail) &&
            !is_conflict(config->ladders, config->num_ladders, head, tail)) {
            config->snakes[count].start = head;
            config->snakes[count].end = tail;
            count++;
        }
    }

    count = 0;
    while (count < config->num_ladders) {
        int bottom = rand_int(1, board_end / 2);
        int top = rand_int(bottom + 1, board_end - 1);
        if (top == board_end) continue;

        if (!is_conflict(config->ladders, count, bottom, top) &&
            !is_conflict(config->snakes, config->num_snakes, bottom, top)) {
            config->ladders[count].start = bottom;
            config->ladders[count].end = top;
            count++;
        }
    }

    printf("Jumps are being added as Snakes and Ladders...\n");
}
