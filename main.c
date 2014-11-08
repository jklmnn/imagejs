#include <stdio.h>
#include <stdlib.h>

#include "gif.h"

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("ImageJs Version 0.1\n");
		printf("Usage: %s [javascript file]\n", argv[0]);
		return 1;
	}
	FILE *in;
	FILE *out;
	int filesize;
	char *buf;
	in = fopen(argv[1], "r");
	out = fopen("out.gif", "w");
	fseek(in, 0, SEEK_END);
	filesize = ftell(in);
	rewind(in);
	buf = (char*)malloc(filesize * sizeof(char));
	fread(buf, 1, filesize, in);
	fclose(in);
	char* outbuf = generate(buf, filesize);
	for(int i = 0; i < filesize + 18; i++){
		fprintf(out,"%c", outbuf[i]);
	}
	fclose(out);
	free(buf);
	free(outbuf);
	return 0;
}
	
