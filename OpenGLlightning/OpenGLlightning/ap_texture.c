#include "ap_texture.h"
#include <string.h>
#include <GL/FreeImage.h>

GLuint Texture_Create(char * file_name) {
	GLuint TextureID;
	FIBITMAP * dib = FreeImage_Load(FreeImage_GetFileType(file_name, strlen(file_name)), file_name, PNG_DEFAULT);

	int Width = FreeImage_GetWidth(dib);
	int Height = FreeImage_GetHeight(dib);

	BYTE * Data = FreeImage_GetBits(dib);

	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, Data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	FreeImage_Unload(dib);
	return TextureID;
}