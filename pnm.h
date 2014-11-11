/*
File: pnm.h
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#ifndef PNM_H
#define PNM_H

#include <stdlib.h>
#include <string.h>

#define PNM_JS_HEADER 19
#define PNM_ENDING 5

char *pnm_js(char*, int);
char *pnm_filename(char*, int);

#endif
