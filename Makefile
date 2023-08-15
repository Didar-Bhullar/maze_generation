build:
	gcc -o main.o main.c maze.c stack.c cell.c -Wall -Wextra

run:
	./main.o

clean:
	rm -rf *.o