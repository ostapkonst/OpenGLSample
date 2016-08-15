#version 330 core
uniform float scale;
in vec3 position; 
in vec3 color;
out vec3 fragmentColor;
void main(void){
	gl_Position = vec4(scale * position, 1.0);
	fragmentColor = color;
};