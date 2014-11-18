/*
File: webp.h
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#ifndef WEBP_H
#define WEBP_H

#include <stdlib.h>
#include <string.h>

#define WEBP_JS_HEADER 18
#define WEBP_JS_HEADER_I 6
#define WEBP_ENDING 6

char *webp_js(char*, int);
char *webp_js_i(char*, int, char*, int);
char *webp_filename(char*, int);

#endif
