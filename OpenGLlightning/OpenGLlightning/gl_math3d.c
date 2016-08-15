#include "gl_math3d.h"

gl_vec3 gl_zero_v3() {
	return v3_create_fill(0, 0, 0);
}

gl_vec3 gl_x_v3() {
	return v3_create_fill(1, 0, 0);
}

gl_vec3 gl_y_v3() {
	return v3_create_fill(0, 1, 0);
}

gl_vec3 gl_z_v3() {
	return v3_create_fill(0, 0, 1);
}

gl_vec4 gl_zero_v4() {
	return v4_create_fill(0, 0, 0, 0);
}

gl_vec4 gl_x_v4() {
	return v4_create_fill(1, 0, 0, 0);
}

gl_vec4 gl_y_v4() {
	return v4_create_fill(0, 1, 0, 0);
}

gl_vec4 gl_z_v4() {
	return v4_create_fill(0, 0, 1, 0);
}

gl_vec4 gl_w_v4() {
	return v4_create_fill(0, 0, 0, 1);
}

gl_mat3 gl_identity_m3() {
	return m3_create_fill(1, 0, 0,
						  0, 1, 0,
						  0, 0, 1);
}
gl_mat3 gl_zero_m3() {
	return m3_create_fill(0, 0, 0,
						  0, 0, 0,
						  0, 0, 0);
}

gl_mat4 gl_identity_m4() {
	return m4_create_fill(1, 0, 0, 0,
						  0, 1, 0, 0,
						  0, 0, 1, 0,
						  0, 0, 0, 1);
}
gl_mat4 gl_zero_m4() {
	return m4_create_fill(0, 0, 0, 0,
						  0, 0, 0, 0,
						  0, 0, 0, 0,
						  0, 0, 0, 0);
}

gl_vec3 gl_mult_m3_v3(gl_mat3 m1, gl_vec3 v1) {
	return v3_create_fill(
		   *m3_00(m1) * *v3_x(v1) + *m3_01(m1) * *v3_y(v1) + *m3_02(m1) * *v3_z(v1),
		   *m3_10(m1) * *v3_x(v1) + *m3_11(m1) * *v3_y(v1) + *m3_12(m1) * *v3_z(v1),
		   *m3_20(m1) * *v3_x(v1) + *m3_21(m1) * *v3_y(v1) + *m3_22(m1) * *v3_z(v1));
}

gl_vec3 gl_mult_m4_v3(gl_mat4 m1, gl_vec3 v1) {
	return v3_create_fill(
		   *m4_00(m1) * *v3_x(v1) + *m4_01(m1) * *v3_y(v1) + *m4_02(m1) * *v3_z(v1) + *m4_03(m1),
		   *m4_10(m1) * *v3_x(v1) + *m4_11(m1) * *v3_y(v1) + *m4_12(m1) * *v3_z(v1) + *m4_13(m1),
		   *m4_20(m1) * *v3_x(v1) + *m4_21(m1) * *v3_y(v1) + *m4_22(m1) * *v3_z(v1) + *m4_23(m1));
}

gl_vec4 gl_mult_m4_v4(gl_mat4 m1, gl_vec4 v1) {
	return v4_create_fill(
		   *m4_00(m1) * *v4_x(v1) + *m4_01(m1) * *v4_y(v1) + *m4_02(m1) * *v4_z(v1) + *m4_03(m1) * *v4_w(v1),
		   *m4_10(m1) * *v4_x(v1) + *m4_11(m1) * *v4_y(v1) + *m4_12(m1) * *v4_z(v1) + *m4_13(m1) * *v4_w(v1),
		   *m4_20(m1) * *v4_x(v1) + *m4_21(m1) * *v4_y(v1) + *m4_22(m1) * *v4_z(v1) + *m4_23(m1) * *v4_w(v1),
		   *m4_30(m1) * *v4_x(v1) + *m4_31(m1) * *v4_y(v1) + *m4_32(m1) * *v4_z(v1) + *m4_33(m1) * *v4_w(v1));
}

gl_mat3 gl_m4_to_m3(gl_mat4 m1) {
	return m3_create_fill(
		   *m4_00(m1), *m4_01(m1), *m4_02(m1),
		   *m4_10(m1), *m4_11(m1), *m4_12(m1),
		   *m4_20(m1), *m4_21(m1), *m4_22(m1));
}

gl_mat4 gl_m3_to_m4(gl_mat3 m1) {
	return m4_create_fill(
		   *m3_00(m1), *m3_01(m1), *m3_02(m1), 0,
		   *m3_10(m1), *m3_11(m1), *m3_12(m1), 0,
		   *m3_20(m1), *m3_21(m1), *m3_22(m1), 0,
		   0, 0, 0, 1);
}

gl_vec3 gl_v4_to_v3(gl_vec4 v1) {
	return v3_create_fill(*v4_x(v1), *v4_y(v1), *v4_z(v1));
}

gl_vec4 gl_v3_to_v4(gl_vec3 v1) {
	return v4_create_fill(*v3_x(v1), *v3_y(v1), *v3_z(v1), 0);
}
