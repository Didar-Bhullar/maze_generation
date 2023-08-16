build:
	gcc -o main.o main.c maze.c stack.c cell.c  drawer.c -Wall -Wextra -lSDL2 -O3

run:
	./main.o 26 20

clean:
	rm -rf *.o