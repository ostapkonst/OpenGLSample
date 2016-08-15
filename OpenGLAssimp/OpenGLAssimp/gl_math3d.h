#ifndef GL_MATH3D_H
#define GL_MATH3D_H

#include "gl_vec3.h"
#include "gl_vec4.h"
#include "gl_mat3.h"
#include "gl_mat4.h"

extern gl_vec3 gl_zero_v3();
extern gl_vec3 gl_x_v3();
extern gl_vec3 gl_y_v3();
extern gl_vec3 gl_z_v3();

extern gl_vec4 gl_zero_v4();
extern gl_vec4 gl_x_v4();
extern gl_vec4 gl_y_v4();
extern gl_vec4 gl_z_v4();
extern gl_vec4 gl_w_v4();

extern gl_mat3 gl_identity_m3();
extern gl_mat3 gl_zero_m3();

extern gl_mat4 gl_identity_m4();
extern gl_mat4 gl_zero_m4();

extern gl_vec3 gl_mult_m3_v3(gl_mat3 m1, gl_vec3 v1);
extern gl_vec3 gl_mult_m4_v3(gl_mat4 m1, gl_vec3 v1);
extern gl_vec4 gl_mult_m4_v4(gl_mat4 m1, gl_vec4 v1);

extern gl_mat3 gl_m4_to_m3(gl_mat4 m1);
extern gl_mat4 gl_m3_to_m4(gl_mat3 m1);

extern gl_vec3 gl_v4_to_v3(gl_mat4 v1);
extern gl_vec4 gl_v3_to_v4(gl_mat3 v1);

#endif