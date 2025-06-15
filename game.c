#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "game.h"
#include "utils.h"

// Global statistics
static long long total_rolls = 0;
static int shortest_win = INT_MAX;
static int best_sequence[MAX_SEQ_LEN];
static int snake_usage[1000] = { 0 };
static int ladder_usage[1000] = { 0 };

// Check if the player lands on a snake or ladder and apply the jump
static int apply_jumps(int pos, GameConfig* config) {
    // Check if on a snake head
    for (int i = 0; i < config->num_snakes; ++i) {
        if (config->snakes[i].start == pos) {
            snake_usage[pos]++; // Count snake usage
            return config->snakes[i].end;
        }
    }

    // Check if on a ladder base
    for (int i = 0; i < config->num_ladders; ++i) {
        if (config->ladders[i].start == pos) {
            ladder_usage[pos]++; // Count ladder usage
            return config->ladders[i].end;
        }
    }

    // No jump occurred
    return pos;
}

// Simulate multiple games using Monte Carlo method
void simulate_games(GameConfig* config) {
    for (int sim = 0; sim < config->simulations; ++sim) {
        int pos = 0;                // Start position
        int rolls = 0;              // Number of rolls taken in this game
        int seq[MAX_SEQ_LEN];      // Store the sequence of rolls

        while (rolls < config->max_steps) {
            int roll = rand_int(1, config->die_sides); // Simulate die roll
            seq[rolls] = roll;

            int next = pos + roll;

            // If move goes beyond board, game ends (depending on rule)
            if (next >= config->board_size)
                break;

            // Apply snake/ladder jump if any
            next = apply_jumps(next, config);
            pos = next;
            rolls++;

            // Check for win
            if (pos == config->board_size - 1)
                break;
        }

        total_rolls += rolls; // Track total rolls for average calculation

        // Update shortest win sequence if this one is better
        if (pos == config->board_size - 1 && rolls < shortest_win) {
            shortest_win = rolls;
            memcpy(best_sequence, seq, sizeof(int) * rolls);
        }
    }
}

// Print statistics after all simulations
void print_statistics(GameConfig* config) {
    printf("\n=== 🎲 Dice Roll Statistics ===\n");
    printf("Average rolls to win the game: %.2f\n", (double)total_rolls / config->simulations);
    printf("Shortest win: %d rolls\n", shortest_win);
    printf("Sequence: ");
    for (int i = 0; i < shortest_win; ++i)
        printf("%d ", best_sequence[i]);
    printf("\n");

    printf("\n=== 🐍 Snakes Usage ===\n");
    for (int i = 0; i < config->num_snakes; ++i)
        printf("Snake at field %d used %d times\n",
            config->snakes[i].start,
            snake_usage[config->snakes[i].start]);

    printf("\n=== 🪜 Ladders Usage ===\n");
    for (int i = 0; i < config->num_ladders; ++i)
        printf("Ladder at field %d used %d times\n",
            config->ladders[i].start,
            ladder_usage[config->ladders[i].start]);
}

