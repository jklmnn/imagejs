#File: Makefile
#Project: imagejs
#Author: jklmnn
#Homepage: http://jklmnn.de/imagejs/
#License: GNU GENERAL PUBLIC LICENSE Version 3

NAME := imagejs
SRC := gif.c bmp.c webp.c pnm.c pgf.c main.c
OBJ := gif.o bmp.o webp.o pnm.o pgf.o main.o
LD := -lm

all:
	#all
	gcc -std=c11 -c $(SRC)
	gcc $(OBJ) -o $(NAME) $(LD)
	rm -f $(OBJ)
i386:
	#linux i386
	gcc -m32 -std=c11 -c $(SRC) 
	gcc -m32 $(OBJ) -o $(NAME).i386 $(LD)
	rm -f $(OBJ)
amd64:
	#linux x86_64
	gcc -m64 -std=c11 -c $(SRC) 
	gcc -m64 $(OBJ) -o $(NAME).x86_64 $(LD)
	rm -f $(OBJ)
armhf:
	#linux armhf
	gcc -std=c99 -c $(SRC)
	gcc $(OBJ) -o $(NAME).armhf $(LD)
	rm -f $(OBJ)
win32:
	#windows i386
	i686-w64-mingw32-gcc -std=c11 -c $(SRC) 
	i686-w64-mingw32-gcc $(OBJ) -o $(NAME).exe $(LD)
	rm -f $(OBJ)
mach-o32:
	#macos i386
	i686-apple-darwin10-gcc -m32 -std=c99 -c $(SRC)
	i686-apple-darwin10-gcc -m32 $(OBJ) -o $(NAME).macho-i386 $(LD)
	rm -f $(OBJ)
mach-o64:
	#macos x86_64
	i686-apple-darwin10-gcc -m64 -std=c99 -c $(SRC)
	i686-apple-darwin10-gcc -m64 $(OBJ) -o $(NAME).macho-x86_64 $(LD)
	rm -f $(OBJ)
release:
	#release versions
	make amd64
	make i386
	make win32
	make mach-o32
	make mach-o64
clean:
	#clean
	rm -f $(NAME)*
	rm -f $(OBJ)
