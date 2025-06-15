#ifndef GAME_H
#define GAME_H

#define MAX_JUMPS 100
#define MAX_SEQ_LEN 1000

typedef struct {
    int start;
    int end;
} Jump;

typedef struct {
    int board_size;
    int die_sides;
    int max_steps;
    int simulations;

    Jump snakes[MAX_JUMPS];
    int num_snakes;

    Jump ladders[MAX_JUMPS];
    int num_ladders;
} GameConfig;

void setup_board(GameConfig* config);
void simulate_games(GameConfig* config);
void print_statistics(GameConfig* config);

#endif
