all:
	gcc -std=c11 gif.c main.c -o imagejs
clean:
	rm imagejs
