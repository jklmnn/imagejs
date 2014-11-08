#include "gif.h"

char* gif_js(char *content, int size){
	char _gif_header[GIF_JS_HEADER] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a, 0x00, 0x30, 0x00, 0x00, 0x3b, 0x2a, 0x2f, 0x3d, 0x30, 0x0a};
	char *buffer = (char*)malloc(GIF_JS_HEADER + size);
	for(int i = 0; i < GIF_JS_HEADER; i++){
		buffer[i] = _gif_header[i];
	}
	for(int i = 0; i < size; i++){
		buffer[i+GIF_JS_HEADER] = content[i];
	}
	return buffer;
}
