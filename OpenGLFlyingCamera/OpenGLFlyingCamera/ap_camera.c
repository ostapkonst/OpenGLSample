#include "ap_camera.h"

/*
	ВНИМАНИЕ: В модуле происходит утечка памяти т.к. 
	типы gl_vec3, gl_vec4, gl_mat3, gl_mat4 объявленны как 
	void * это было сдаланно с пожелания преподавателя.
	Нужно либо переписать библиотеки работы с math, либо
	очищать память функциями в библиотеке.
*/

void Camera_Create(Camera * camera, float x, float y, float z) {
	camera->position = v3_create_fill(x, y, z);
	camera->projection = gl_identity_m4();
	camera->rotation = gl_zero_v3();
}

void Camera_Perspective(Camera * camera, float fov, float aspect, float zNear, float zFar) {
	camera->projection = gr_perspective(fov, aspect, zNear, zFar);
}

void Camera_Rotate(Camera *camera, float x, float y, float z) {
	v3_ch_add(camera->rotation, v3_create_fill(x, y, z));
}

void Camera_Move(Camera *camera, float x, float y, float z) {
	v3_ch_add(camera->position, gl_mult_m3_v3(m3_transp(gl_m4_to_m3(gr_rotation_v(camera->rotation))), v3_create_fill(x, y, z)));
}

gl_mat4 Camera_GetProjectionMatrix(Camera *camera) {
	return m4_multipli(camera->projection, m4_multipli(gr_rotation_v(camera->rotation), gr_translation_v(v3_mult_value(camera->position, -1))));
}