all:
	gcc -std=c11 gif.c main.c -o gifjs
clean:
	rm gifjs
