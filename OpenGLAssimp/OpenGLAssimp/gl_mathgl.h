#ifndef MATHGL_H
#define MATHGL_H

#include "gl_math3d.h"

extern gl_mat4 gr_rotation_x(float angle);
extern gl_mat4 gr_rotation_y(float angle);
extern gl_mat4 gr_rotation_z(float angle);

extern gl_mat4 gr_rotation(float x, float y, float z);
extern gl_mat4 gr_rotation_v(gl_vec3 v1);

extern gl_mat4 gr_scale(float x, float y, float z);
extern gl_mat4 gr_scale_v(gl_vec3 v1);

extern gl_mat4 gr_translation(float x, float y, float z);
extern gl_mat4 gr_translation_v(gl_vec3 v1);

extern gl_mat4 gr_orthographic(float left, float right,
	float bottom, float top, float zNear, float zFar);
extern gl_mat4 gr_perspective(float fov, float aspect, float zNear, float zFar);
extern gl_mat4 gr_frustum(float left, float right,
	float bottom, float top, float zNear, float zFar);
extern gl_mat4 gr_look_at(gl_vec3 position, gl_vec3 center, gl_vec3 up);

#endif