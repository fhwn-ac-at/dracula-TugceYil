CC = clang
CFLAGS = -Wall -Wextra -Werror

all: simulator

simulator: main.o game.o board.o utils.o
	$(CC) $(CFLAGS) -o simulator main.o game.o board.o utils.o

clean:
	rm -f *.o simulator

