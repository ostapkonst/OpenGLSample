#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

const int NUM_VERTICES = 3;
const int VERTEX_SIZE = 6 * sizeof(float);
const int VERTEX_COLOR_OFFSET = 3 * sizeof(float);

GLuint vbo, vao;
GLuint program;
float scale = 0.3f;

const float vertices[] = {
    -2.0f, -2.0f, -1.0f,  1.0f, 0.0f, 0.0f,
    0.0f,  2.0f, -1.0f,	  0.0f, 1.0f, 0.0f,
    2.0f, -2.0f, -1.0f,	  0.0f, 0.0f, 1.0f
};

char * loadFile(const char * fileName) { 
	char * str_file; 
	FILE * fp = fopen(fileName, "r");
	int i = 0; 	
	char ch; 

	str_file = malloc(sizeof(char));
	while((ch = getc(fp)) != EOF) { 
		str_file[i++]=ch; 
		str_file = realloc(str_file, sizeof(char) * i + 1);
	}
	str_file[i] = '\0'; 
	printf("%s\n", str_file); 
	fclose(fp); 
	
	return str_file;
}

GLuint loadShader(const char * source, GLenum type) {
    GLuint shader = glCreateShader(type);
    GLint len = strlen(source);

    glShaderSource(shader, 1, &source,  &len);
  
    return shader;
}

GLuint createProgram() {
    GLuint program = glCreateProgram();
    GLuint vs = loadShader(loadFile("vertex.vsh"), GL_VERTEX_SHADER);
    GLuint fs = loadShader(loadFile("fragment.fsh"), GL_FRAGMENT_SHADER);
	
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
	
    return program;
}

void setAttrPtr(GLuint program, const char * name, int numComponents, GLsizei stride, const GLvoid * offset) {
    int	loc = glGetAttribLocation(program, name);
		
    glVertexAttribPointer(loc, numComponents, GL_FLOAT, GL_TRUE, stride, offset);		
    glEnableVertexAttribArray(loc);
}

void setUniformFloat(GLuint program, const char * name, float value) {
    glUniform1f(glGetUniformLocation(program, name), value);
}

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, NUM_VERTICES);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void key(unsigned char key, int x, int y) {
    if (key == 27 || key == 'q' || key == 'Q') exit (0);
}

void mouseWheel(int wheel, int dir, int mouseX, int mouseY) {
	if (dir > 0) {
		if (scale < 0.9)
			scale += 0.02f;
	} else {
		if (scale > 0.02)
            scale -= 0.02f;
	}

    setUniformFloat(program, "scale", scale);
    glutPostRedisplay();
}

int main(int argc, char * argv []) {								
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
					
    glutInitContextVersion(3, 0);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG );
    glutInitContextProfile(GLUT_CORE_PROFILE );
	glewExperimental = GL_TRUE;
				
    glutCreateWindow("Triangle GL 3.3");

    glewInit();
								
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutMouseWheelFunc(mouseWheel);

    program = createProgram();
	
    glUseProgram(program);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, NUM_VERTICES * VERTEX_SIZE, vertices, GL_STATIC_DRAW);	
	
	setAttrPtr(program, "color", 3, VERTEX_SIZE, (const GLvoid*)VERTEX_COLOR_OFFSET);
    setAttrPtr(program, "position", 3, VERTEX_SIZE, 0);
    setUniformFloat(program, "scale", scale);

    glutMainLoop ();

    return 0;
}