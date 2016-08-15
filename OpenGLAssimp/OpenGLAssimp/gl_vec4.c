#include "gl_vec4.h"
#include <stdlib.h>
#include <math.h>

typedef struct {
	gl_vec4_type data[4];
} vector4;

gl_vec4 v4_create() {
	return malloc(sizeof(vector4));
}
gl_vec4 v4_create_fill(gl_vec4_type x, gl_vec4_type y, gl_vec4_type z, gl_vec4_type w) {
	vector4 * vc1 = v4_create();
	gl_vec4_type * vd1 = vc1->data;

	vd1[0] = x;
	vd1[1] = y;
	vd1[2] = z;
	vd1[3] = w;

	return vc1;
}
void v4_destroy(gl_vec4 v1) {
	free(v1);
}

void v4_ch_add(gl_vec4 v1, gl_vec4 v2) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;
	gl_vec4_type * vd2 = ((vector4 *)v2)->data;

	vd1[0] += vd2[0];
	vd1[1] += vd2[1];
	vd1[2] += vd2[2];
	vd1[3] += vd2[3];
}

void v4_ch_mult(gl_vec4 v1, gl_vec4 v2) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;
	gl_vec4_type * vd2 = ((vector4 *)v2)->data;

	vd1[0] *= vd2[0];
	vd1[1] *= vd2[1];
	vd1[2] *= vd2[2];
	vd1[3] *= vd2[3];
}

void v4_ch_sub(gl_vec4 v1, gl_vec4 v2) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;
	gl_vec4_type * vd2 = ((vector4 *)v2)->data;

	vd1[0] -= vd2[0];
	vd1[1] -= vd2[1];
	vd1[2] -= vd2[2];
	vd1[3] -= vd2[3];
}
void v4_ch_div(gl_vec4 v1, gl_vec4 v2) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;
	gl_vec4_type * vd2 = ((vector4 *)v2)->data;

	vd1[0] /= vd2[0];
	vd1[1] /= vd2[1];
	vd1[2] /= vd2[2];
	vd1[3] /= vd2[3];
}

gl_vec4 v4_coppy(gl_vec4 v1) {
	gl_vec4_type * vd2 = ((vector4 *)v1)->data;

	return v4_create_fill(vd2[0], vd2[1], vd2[2], vd2[3]);
}

gl_vec4 v4_mult(gl_vec4 v1, gl_vec4 v2) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_mult(vc1, v2);

	return vc1;
}

gl_vec4 v4_sub(gl_vec4 v1, gl_vec4 v2) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_sub(vc1, v2);

	return vc1;
}

gl_vec4 v4_div(gl_vec4 v1, gl_vec4 v2) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_div(vc1, v2);

	return vc1;
}

gl_vec4 v4_add(gl_vec4 v1, gl_vec4 v2) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_add(vc1, v2);

	return vc1;
}


gl_vec4_type v4_dot(gl_vec4 v1, gl_vec4 v2) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;
	gl_vec4_type * vd2 = ((vector4 *)v2)->data;

	return vd1[0] * vd2[0] + 
		   vd1[1] * vd2[1] + 
		   vd1[2] * vd2[2] +
		   vd1[3] * vd2[3];
}


gl_vec4_type v4_len(gl_vec4 vc1) {
	return sqrtf(v4_dot(vc1, vc1));
}

gl_vec4_type v4_dist(gl_vec4 v1, gl_vec4 v2) {
	vector4 * vc1 = v4_sub(v1, v2);
	gl_vec4_type len = v4_len(vc1);
	v4_destroy(vc1);

	return len;
}

gl_vec4 v4_norm(gl_vec4 v1) {
	return v4_div_value(v1, v4_len(v1));
}

gl_vec4_type * v4_x(gl_vec4 v1) {
	return &((vector4 *)v1)->data[0];
}

gl_vec4_type * v4_y(gl_vec4 v1) {
	return &((vector4 *)v1)->data[1];
}

gl_vec4_type * v4_z(gl_vec4 v1) {
	return &((vector4 *)v1)->data[2];
}

gl_vec4_type * v4_w(gl_vec4 v1) {
	return &((vector4 *)v1)->data[3];
}

void v4_ch_add_value(gl_vec4 v1, gl_vec4_type val) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;

	vd1[0] += val;
	vd1[1] += val;
	vd1[2] += val;
	vd1[3] += val;
}

void v4_ch_mult_value(gl_vec4 v1, gl_vec4_type val) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;

	vd1[0] *= val;
	vd1[1] *= val;
	vd1[2] *= val;
	vd1[3] *= val;
}

void v4_ch_sub_value(gl_vec4 v1, gl_vec4_type val) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;

	vd1[0] -= val;
	vd1[1] -= val;
	vd1[2] -= val;
	vd1[3] -= val;
}

void v4_ch_div_value(gl_vec4 v1, gl_vec4_type val) {
	gl_vec4_type * vd1 = ((vector4 *)v1)->data;

	vd1[0] /= val;
	vd1[1] /= val;
	vd1[2] /= val;
	vd1[3] /= val;
}

gl_vec4 v4_mult_value(gl_vec4 v1, gl_vec4_type val) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_mult_value(vc1, val);

	return vc1;
}

gl_vec4 v4_sub_value(gl_vec4 v1, gl_vec4_type val) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_sub_value(vc1, val);

	return vc1;
}

gl_vec4 v4_div_value(gl_vec4 v1, gl_vec4_type val) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_div_value(vc1, val);

	return vc1;
}

gl_vec4 v4_add_value(gl_vec4 v1, gl_vec4_type val) {
	vector4 * vc1 = v4_coppy(v1);
	v4_ch_add_value(vc1, val);

	return vc1;
}