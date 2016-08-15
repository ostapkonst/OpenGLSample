#ifndef IN_FILES_H
#define IN_FILES_H

extern char * File_Open_Buffer(char * file_name);
extern char * File_Open_Char(char * file_name);
extern void File_Save_Buffer(char * file_name, char * text);
extern void File_Save_Char(char * file_name, char * text);

#endif