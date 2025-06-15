#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    GameConfig config = parse_arguments(argc, argv);

    srand((unsigned int)time(NULL));

    setup_board(&config);

    simulate_games(&config);

    print_statistics(&config);

    return 0;
}
