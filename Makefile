all:
	gcc -std=c11 gif.c bmp.c main.c -o imagejs
i386:
	gcc -m32 -std=c11 gif.c bmp.c main.c -o imagejs.i386
amd64:
	gcc -m64 -std=c11 gif.c bmp.c main.c -o imagejs.amd64
win32:
	i686-w64-mingw32-gcc -std=c11 gif.c bmp.c main.c -o imagejs.exe
clean:
	rm imagejs*
