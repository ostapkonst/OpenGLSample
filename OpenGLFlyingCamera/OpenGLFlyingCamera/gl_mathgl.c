#include "gl_mathgl.h"
#include "math.h"

const float math_epsilon = 1e-5f;
const float math_pi	  = 3.1415926536f;
const float math_radians = 3.1415926536f  / 180.0f;
const float math_degrees = 180.0f / 3.1415926536f;

gl_mat4 gr_rotation_x(float angle) {
	float c = cosf(angle * math_radians), 
		  s = sinf(angle * math_radians);

	return  m4_create_fill(1, 0, 0, 0,
						   0, c,-s, 0,
						   0, s, c, 0,
						   0, 0, 0, 1);
}

gl_mat4 gr_rotation_y(float angle) {
	float c = cosf(angle * math_radians), 
		  s = sinf(angle * math_radians);

	return m4_create_fill(c, 0, s, 0,
						  0, 1, 0, 0,
						 -s, 0, c, 0,
						  0, 0, 0, 1);
}

gl_mat4 gr_rotation_z(float angle) {
	float c = cosf(angle * math_radians), 
		  s = sinf(angle * math_radians);

	return m4_create_fill(c,-s, 0, 0,
						  s, c, 0, 0,
						  0, 0, 1, 0,
						  0, 0, 0, 1);
}

gl_mat4 gr_rotation(float x, float y, float z) {
	float cx = cosf(x * math_radians), sx = sinf(x * math_radians),
		  cy = cosf(y * math_radians), sy = sinf(y * math_radians),
		  cz = cosf(z * math_radians), sz = sinf(z * math_radians);

	return m4_create_fill(cy * cz, -cy * sz, sy, 0,
						  cx * sz + sx * cz * sy, cx * cz - sx * sy * sz, -cy * sx, 0,
						  sx * sz - cx * cz * sy, cz * sx + cx * sy * sz, cx * cy, 0,
						  0, 0, 0, 1);
}

gl_mat4 gr_rotation_v(gl_vec3 v1) {
	return gr_rotation(*v3_x(v1), *v3_y(v1), *v3_z(v1));
}

gl_mat4 gr_scale(float x, float y, float z) {
	return m4_create_fill(x, 0, 0, 0,
						  0, y, 0, 0,
						  0, 0, z, 0,
						  0, 0, 0, 1);
}

gl_mat4 gr_scale_v(gl_vec3 v1) {
	return gr_scale(*v3_x(v1), *v3_y(v1), *v3_z(v1));
}

gl_mat4 gr_translation(float x, float y, float z) {
	return m4_create_fill(1, 0, 0, x,
						  0, 1, 0, y,
						  0, 0, 1, z,
						  0, 0, 0, 1);
}

gl_mat4 gr_translation_v(gl_vec3 v1) {
	return gr_translation(*v3_x(v1), *v3_y(v1), *v3_z(v1));
}

gl_mat4 gr_orthographic(float left, float right,
	float bottom, float top, float zNear, float zFar) {
	float tx = - (right + left) / (right - left),
		  ty = - (top + bottom) / (top - bottom),
		  tz = - (zFar + zNear) / (zFar - zNear);

	return m4_create_fill(2 / (right - left), 0, 0, tx,
						  0, 2 / (top - bottom), 0, ty,
						  0, 0, -2 / (zFar - zNear), tz,
						  0, 0, 0, 1);
}

gl_mat4 gr_perspective(float fov, float aspect, float zNear, float zFar) {
	float f = 1 / tanf(fov * math_radians / 2),
		  A = (zFar + zNear) / (zNear - zFar),
		  B = (2 * zFar * zNear) / (zNear - zFar);

	return m4_create_fill(f / aspect, 0, 0, 0,
						  0, f, 0, 0,
						  0, 0, A, B,
						  0, 0, -1, 0);
}

gl_mat4 gr_frustum(float left, float right,
	float bottom, float top, float zNear, float zFar) {

	return m4_create_fill((2 * zNear) / (right - left), 0, (right + left) / (right - left), 0,
						   0, (2 * zNear) / (top - bottom), (top + bottom) / (top - bottom), 0,
						   0, 0, -(zFar + zNear) / (zFar - zNear), -(2 * zFar * zNear) / (zFar - zNear),
						   0, 0, -1, 0);
}

gl_mat4 gr_look_at(gl_vec3 position, gl_vec3 center, gl_vec3 up) {

	gl_vec3 f = v3_norm(v3_sub(position, center));
	gl_vec3 s = v3_norm(v3_cross(up, f));
	gl_vec3 u = v3_norm(v3_cross(f, s));

	return m4_create_fill(*v3_x(s), *v3_y(s), *v3_z(s), -v3_dot(s, position),
						  *v3_x(u), *v3_y(u), *v3_z(u), -v3_dot(u, position),
						  *v3_x(f), *v3_y(f), *v3_z(f), -v3_dot(f, position),
						  0, 0, 0, 1);
}
