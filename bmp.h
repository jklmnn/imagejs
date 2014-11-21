/*
File: bmp.h
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/


#ifndef BMP_H
#define BMP_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BMP_JS_HEADER 139
#define BMP_JS_HEADER_V 134
#define BMP_JS_HEADER_M 96
#define BMP_JS_HEADER_I 3
#define BMP_ENDING 5

char *bmp_js(char*, int);
char *bmp_js_l(char*, int);
char *bmp_js_m(char*, int);
char *bmp_js_i(char*, int, char*, int);
char *bmp_filename(char*, int);
unsigned int *getsize(int);
char *createline(char*, int);
char *chunk(char*, int);

#endif
