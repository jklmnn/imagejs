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

#define BMP_JS_HEADER 139
#define BMP_JS_HEADER_L 134
#define BMP_JS_HEADER_I 3
#define BMP_ENDING 5

char *bmp_js(char*, int);
char *bmp_js_l(char*, int);
char *bmp_js_i(char*, int, char*, int);
char *bmp_filename(char*, int);

#endif
