build:
	gcc -o maze_generation.o maze_generation.c

run:
	./maze_generation.o

clean:
	rm -rf *.o