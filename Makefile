#File: Makefile
#Project: imagejs
#Author: jklmnn
#Homepage: http://jklmnn.de/imagejs/
#License: GNU GENERAL PUBLIC LICENSE Version 3

all:
	gcc -std=c11 -c gif.c bmp.c webp.c pnm.c main.c
	gcc *.o -o imagejs
i386:
	gcc -m32 -std=c11 -c gif.c bmp.c webp.c pnm.c main.c 
	gcc -m32 *.o -o imagejs.i386
amd64:
	gcc -m64 -std=c11 -c gif.c bmp.c webp.c pnm.c main.c 
	gcc -m64 *.o -o imagejs.amd64
win32:
	i686-w64-mingw32-gcc -std=c11 -c gif.c bmp.c webp.c pnm.c main.c 
	i686-w64-mingw32-gcc *.o -o imagejs.exe
release:
	make amd64
	make i386
	make win32
	rm -r *.o
clean:
	touch imagejs
	touch .o
	rm -r imagejs*
	rm -r *.o
