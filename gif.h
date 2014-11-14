/*
File: gif.h
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/


#ifndef GIF_H
#define GIF_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define GIF_JS_HEADER 19
#define GIF_JS_HEADER_I 6
#define GIF_ENDING 5

char *gif_js(char*, int);
char *gif_js_i(char*, int, char*, int);
char *gif_filename(char*, int);
void writebuffer(char *, int);

#endif
