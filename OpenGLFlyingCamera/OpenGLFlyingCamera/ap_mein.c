#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "in_files.h"
#include "ap_figures.h"
#include "ap_camera.h"

const int NUM_VERTICES = 400;
const int VERTEX_SIZE = 3 * sizeof(float);

GLuint vbo, vao;
GLuint program;
Camera mainCamera;


void CameraSetup(GLuint program, Camera *camera) {
	glUniformMatrix4fv(glGetUniformLocation(program, "projection"),
		1, GL_TRUE, Camera_GetProjectionMatrix(camera));
}

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

void SetAttrPtr(GLuint program, char * name, int numComponents, GLsizei stride) {
	int	loc = glGetAttribLocation(program, name);
		
	glVertexAttribPointer(loc, numComponents, GL_FLOAT, GL_FALSE, stride, 0);		
	glEnableVertexAttribArray(loc);
}

void Display(void) {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawArrays(GL_LINES, 0, NUM_VERTICES);

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

	CameraSetup(program, &mainCamera);
	glutPostRedisplay();
}

void Mouse(int x, int y) {
	int rotate_0 = 0, rotate_1 = 0;

	if (x == 400 && y == 400) return; 

	rotate_1 = x - 400;
	rotate_0 = y - 400;

	glutWarpPointer(400, 400);

	Camera_Rotate(&mainCamera,rotate_0 * 0.04f, rotate_1 * 0.04f, 0.0f);
	CameraSetup(program, &mainCamera);

	glutPostRedisplay();
}

int main(int argc, char * argv []) {

	float * grid = Figure_Grid(-30,-1,-30,100,1);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	glutInitContextVersion(3, 2);
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

	program = CreateProgram();

	glUseProgram(program);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, NUM_VERTICES * VERTEX_SIZE, grid, GL_STATIC_DRAW);	

	SetAttrPtr(program, "position", 3, VERTEX_SIZE);

	Camera_Create(&mainCamera, 0.0f, 0.0f, 12.0f);
	Camera_Perspective(&mainCamera, 45.0f, 1, 0.1f, 300.0f);
	CameraSetup(program, &mainCamera);

	glutMainLoop();

	return 0;
}