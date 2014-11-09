all:
	gcc -std=c11 gif.c bmp.c main.c -o imagejs
clean:
	rm imagejs
