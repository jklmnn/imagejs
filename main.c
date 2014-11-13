/*
File: main.c
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "meta.h"
#include "gif.h"
#include "bmp.h"
#include "webp.h"
#include "pnm.h"
#include "pgf.h"

int getlen(char* str){
	int i;
	for(i = 0; str[i] != 0; i++);
	return i;
}

void _help(char *name, int type){
	switch(type){
		case 0:
			printf("ImageJs Version %d.%d.%d\n", VERSION_MAJ, VERSION_MIN, VERSION_FIX);
			printf("Usage: %s [option] [javascript file] [flags]\n", name);
			printf("Options:  gif, bmp, webp, pnm, pgf\n");
			printf("Flags (optional):	l	prints image as viewable line\n");
			break;
		case 1:
			printf("The flag \"%s\" is currently not supported for this type of file.\n", name);
			break;
		default:
			_help(name, 0);
			break;
	}
}

int main(int argc, char *argv[]){
	if(argc < 3){
		_help(argv[0], 0);
		return 1;
	}
	FILE *in;
	FILE *out;
	int filesize;
	char *buf;
	in = fopen(argv[2], "rb");
	if(in){
		fseek(in, 0, SEEK_END);
		filesize = ftell(in);
		rewind(in);
		buf = (char*)malloc(filesize * sizeof(char));
		fread(buf, 1, filesize, in);
		fclose(in);
	}else{
		printf("File %s could not be opened!\n", argv[2]);
		return 2;
	}
	char *outbuf;
	if(strcmp(argv[1], "bmp") == 0){
		if(argc > 3){
			if(strcmp(argv[3], "l") == 0){
				outbuf = bmp_js_v(buf, filesize);
				out = fopen(bmp_filename(argv[2], getlen(argv[2])), "wb");
				for(int i = 0; i < filesize + BMP_JS_HEADER_V; i++){
					fprintf(out, "%c", outbuf[i]);
				}
			}else{
				_help(argv[3], 1);
				return 3;
			}
		}else{
			outbuf = bmp_js(buf, filesize);
			out = fopen(bmp_filename(argv[2], getlen(argv[2])), "wb");
			for(int i = 0; i < filesize + BMP_JS_HEADER; i++){
				fprintf(out, "%c", outbuf[i]);
			}
		}
	}else if(strcmp(argv[1], "gif") == 0){
		if(argc > 3){
			_help(argv[3], 1);
			return 3;
		}else{
			outbuf = gif_js(buf, filesize);
			out = fopen(gif_filename(argv[2], getlen(argv[2])), "wb");
			for(int i = 0; i < filesize + GIF_JS_HEADER; i++){
				fprintf(out, "%c", outbuf[i]);
			}
		}
	}else if(strcmp(argv[1], "webp") == 0){
		if(argc > 3){
			_help(argv[3], 1);
			return 3;
		}else{
			outbuf = webp_js(buf, filesize);
			out = fopen(webp_filename(argv[2], getlen(argv[2])), "wb");
			for(int i = 0; i < filesize + WEBP_JS_HEADER; i++){
				fprintf(out, "%c", outbuf[i]);
			}
		}
	}else if(strcmp(argv[1], "pnm") == 0){
		if(argc > 3){
			_help(argv[3], 1);
			return 3;
		}else{
			outbuf = pnm_js(buf, filesize);
			out = fopen(pnm_filename(argv[2], getlen(argv[2])), "wb");
			for(int i = 0; i < filesize + PNM_JS_HEADER; i++){
				fprintf(out, "%c", outbuf[i]);
			}
		}
	}else if(strcmp(argv[1], "pgf") == 0){
		if(argc > 3){
			_help(argv[3], 1);
			return 3;
		}else{
			outbuf = pgf_js(buf, filesize);
			out = fopen(pgf_filename(argv[2], getlen(argv[2])), "wb");
			for(int i = 0; i < filesize + PGF_JS_HEADER; i++){
				fprintf(out, "%c", outbuf[i]);
			}
		}
	}else{
		_help(argv[0], 0);
		free(buf);
		return 1;
	}
	fclose(out);
	free(buf);
	free(outbuf);
	return 0;
}
	
