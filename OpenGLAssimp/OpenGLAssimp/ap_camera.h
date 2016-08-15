#ifndef AP_CAMERA_H
#define AP_CAMERA_H

#include "gl_mathgl.h"
#include <GL/glew.h>

typedef struct{
	gl_vec3 position;
	gl_vec3 rotation;
	gl_mat4 projection;
} Camera;

extern void Camera_Create(Camera * camera, float x, float y, float z);
extern void Camera_Perspective(Camera * camera, float fov, float aspect, float zNear, float zFar);
extern void Camera_Rotate(Camera * camera, float x, float y, float z);
extern void Camera_Move(Camera * camera, float x, float y, float z);
extern void Camera_Setup(GLuint program, Camera * camera);

#endif