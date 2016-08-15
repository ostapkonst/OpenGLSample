#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "FreeImage.lib")
#pragma comment(lib, "Assimp.lib")

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "in_files.h"
#include "ap_figures.h"
#include "ap_camera.h"
#include "ap_model_loader.h"
#include "ap_texture.h"

const int VERTEX_SIZE = 3 * sizeof(float);

GLuint vbo, vao, ind, uv, texture;
int mod_size, ind_size;
GLuint program;
Camera mainCamera;
GLuint TextureID;

GLuint LoadShader(char * source, GLenum type) {
	GLuint shader = glCreateShader(type);
	GLint len = strlen(source);

	glShaderSource(shader, 1, &source,  &len);
  
	return shader;
}

GLuint CreateProgram() {
	char * vt = File_Open_Char("vertex.vsh");
	char * ft = File_Open_Char("fragment.fsh");
	GLuint program = glCreateProgram();
	GLuint vs = LoadShader(vt, GL_VERTEX_SHADER);
	GLuint fs = LoadShader(ft, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);

	free(vt);
	free(ft);

	return program;
}

void Display(void) {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(TextureID, 0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
			0,                  
			3,                  
			GL_FLOAT,           
			GL_FALSE,           
			0,                  
			(void*)0            
		);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glVertexAttribPointer(
			1,                               
			2,                               
			GL_FLOAT,                        
			GL_FALSE,                        
			0,                               
			(void*)0                         
		);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind);
	glDrawElements(GL_TRIANGLES, ind_size * VERTEX_SIZE, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

    glutSwapBuffers();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Key(unsigned char key, int x, int y) {
	int move_0 = 0, move_1 = 0;

	switch (key) {
		case 'w' : move_1 = -1; break;
		case 's' : move_1 = 1; break;
		case 'a' : move_0 = -1; break;
		case 'd' : move_0 = 1; break;
		case 27 : exit(0);
	}

	Camera_Move(&mainCamera, move_0 * 0.4f, 0.0f, move_1 * 0.4f);

	Camera_Setup(program, &mainCamera);
	glutPostRedisplay();
}

void Mouse(int x, int y) {
	int rotate_0 = 0, rotate_1 = 0;

	if (x == 400 && y == 400) return; 

	rotate_1 = x - 400;
	rotate_0 = y - 400;

	glutWarpPointer(400, 400);

	Camera_Rotate(&mainCamera, rotate_0 * 0.04f, rotate_1 * 0.04f, 0.0f);
	Camera_Setup(program, &mainCamera);

	glutPostRedisplay();
}

int main(int argc, char * argv []) {

	unsigned int * indices;
	float * vertices = NULL;
	float * uvs = NULL;
	float * normals = NULL;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);

    glutInitContextVersion(3, 3);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG );
    glutInitContextProfile(GLUT_CORE_PROFILE );
	glewExperimental = GL_TRUE;

    glutCreateWindow("Triangle GL 3.3");

    glewInit();
							
	glutSetCursor(GLUT_CURSOR_NONE); 

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
	glutPassiveMotionFunc(Mouse);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

    program = CreateProgram();
	
    glUseProgram(program);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
	
	Load_Model("cube.obj", &indices, &vertices, &uvs, &normals, &mod_size, &ind_size);	
	texture = Texture_Create("uvmap.DDS");

	TextureID  = glGetUniformLocation(program, "myTextureSampler");

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mod_size * VERTEX_SIZE, vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &ind);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_size * VERTEX_SIZE, indices , GL_STATIC_DRAW);

	glGenBuffers(1, &uv);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glBufferData(GL_ARRAY_BUFFER, mod_size * VERTEX_SIZE, uvs, GL_STATIC_DRAW);

	Camera_Create(&mainCamera, 0.0f, 0.0f, 12.0f);
	Camera_Perspective(&mainCamera, 45.0f, 1, 0.1f, 300.0f);
	Camera_Setup(program, &mainCamera);

    glutMainLoop();

	return 0;
}