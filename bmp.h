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
#define BMP_JS_HEADER_V 134
#define BMP_ENDING 5

char *bmp_js(char*, int);
char *bmp_js_v(char*, int);
char *bmp_filename(char*, int);

#endif
