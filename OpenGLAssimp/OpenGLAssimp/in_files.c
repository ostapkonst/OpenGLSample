#include "in_files.h"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <io.h> 
#include <string.h> 

char * File_Open_Buffer(char * file_name) {
	FILE * fi = fopen(file_name, "r");
	int flen = filelength(fileno(fi));
	char * str = malloc(sizeof(char) * flen);

	fread(str, sizeof(char), flen, fi);
	str[flen] = '\0';
	fclose(fi); 

	return str;
}

char * File_Open_Char(char * file_name) {
	int i = -1; 	
	FILE * fi = fopen(file_name, "r");
	char * str = malloc(sizeof(char));

	while((str[++i] = getc(fi)) != EOF)  
		str = realloc(str, sizeof(char) * (i + 2));

	str[i] = '\0'; 
	fclose(fi); 

	return str;
}

void File_Save_Buffer(char * file_name, char * text) {
	FILE * fo = fopen(file_name, "w");

	fwrite(text, sizeof(char), strlen(text), fo);

	fclose(fo); 
}

void File_Save_Char(char * file_name, char * text) {
	unsigned int i;
	FILE * fo = fopen(file_name, "w");

	for (i = 0; i < strlen(text); i++) 
		putc(text[i], fo);

	fclose(fo); 
}