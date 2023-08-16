build:
	gcc -o main.o main.c maze.c stack.c cell.c  drawer.c -Wall -Wextra -lSDL2

run:
	./main.o

clean:
	rm -rf *.o