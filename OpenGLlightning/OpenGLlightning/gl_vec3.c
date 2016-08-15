#include "gl_vec3.h"
#include <stdlib.h>
#include <math.h>

typedef struct {
	gl_vec3_type data[3];
} vector3;

gl_vec3 v3_create() {
	return malloc(sizeof(vector3));
}
gl_vec3 v3_create_fill(gl_vec3_type x, gl_vec3_type y, gl_vec3_type z) {
	vector3 * vc1 = v3_create();
	gl_vec3_type * vd1 = vc1->data;

	vd1[0] = x;
	vd1[1] = y;
	vd1[2] = z;

	return vc1;
}
void v3_destroy(gl_vec3 v1) {
	free(v1);
}

void v3_ch_add(gl_vec3 v1, gl_vec3 v2) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;
	gl_vec3_type * vd2 = ((vector3 *)v2)->data;

	vd1[0] += vd2[0];
	vd1[1] += vd2[1];
	vd1[2] += vd2[2];
}

void v3_ch_mult(gl_vec3 v1, gl_vec3 v2) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;
	gl_vec3_type * vd2 = ((vector3 *)v2)->data;

	vd1[0] *= vd2[0];
	vd1[1] *= vd2[1];
	vd1[2] *= vd2[2];
}

void v3_ch_sub(gl_vec3 v1, gl_vec3 v2) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;
	gl_vec3_type * vd2 = ((vector3 *)v2)->data;

	vd1[0] -= vd2[0];
	vd1[1] -= vd2[1];
	vd1[2] -= vd2[2];
}
void v3_ch_div(gl_vec3 v1, gl_vec3 v2) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;
	gl_vec3_type * vd2 = ((vector3 *)v2)->data;

	vd1[0] /= vd2[0];
	vd1[1] /= vd2[1];
	vd1[2] /= vd2[2];
}

gl_vec3 v3_coppy(gl_vec3 v1) {
	gl_vec3_type * vd2 = ((vector3 *)v1)->data;

	return v3_create_fill(vd2[0], vd2[1], vd2[2]);
}

gl_vec3 v3_mult(gl_vec3 v1, gl_vec3 v2) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_mult(vc1, v2);

	return vc1;
}

gl_vec3 v3_sub(gl_vec3 v1, gl_vec3 v2) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_sub(vc1, v2);

	return vc1;
}

gl_vec3 v3_div(gl_vec3 v1, gl_vec3 v2) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_div(vc1, v2);

	return vc1;
}

gl_vec3 v3_add(gl_vec3 v1, gl_vec3 v2) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_add(vc1, v2);

	return vc1;
}


gl_vec3_type v3_dot(gl_vec3 v1, gl_vec3 v2) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;
	gl_vec3_type * vd2 = ((vector3 *)v2)->data;

	return vd1[0] * vd2[0] + 
		   vd1[1] * vd2[1] + 
		   vd1[2] * vd2[2];
}

gl_vec3 v3_cross(gl_vec3 v1,gl_vec3 v2) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;
	gl_vec3_type * vd2 = ((vector3 *)v2)->data;

	return v3_create_fill(
		   vd1[1] * vd2[2] - vd1[2] * vd2[1], 						  
		   vd1[2] * vd2[0] - vd1[0] * vd2[2], 
		   vd1[0] * vd2[1] - vd1[1] * vd2[0]);
}

gl_vec3_type v3_len(gl_vec3 vc1) {
	return sqrtf(v3_dot(vc1, vc1));
}

gl_vec3_type v3_dist(gl_vec3 v1, gl_vec3 v2) {
	vector3 * vc1 = v3_sub(v1, v2);
	gl_vec3_type len = v3_len(vc1);
	v3_destroy(vc1);

	return len;
}

gl_vec3 v3_norm(gl_vec3 v1) {
	return v3_div_value(v1, v3_len(v1));
}

gl_vec3_type * v3_x(gl_vec3 v1) {
	return &((vector3 *)v1)->data[0];
}

gl_vec3_type * v3_y(gl_vec3 v1) {
	return &((vector3 *)v1)->data[1];
}

gl_vec3_type * v3_z(gl_vec3 v1) {
	return &((vector3 *)v1)->data[2];
}

void v3_ch_add_value(gl_vec3 v1, gl_vec3_type val) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;

	vd1[0] += val;
	vd1[1] += val;
	vd1[2] += val;
}

void v3_ch_mult_value(gl_vec3 v1, gl_vec3_type val) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;

	vd1[0] *= val;
	vd1[1] *= val;
	vd1[2] *= val;
}

void v3_ch_sub_value(gl_vec3 v1, gl_vec3_type val) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;

	vd1[0] -= val;
	vd1[1] -= val;
	vd1[2] -= val;
}

void v3_ch_div_value(gl_vec3 v1, gl_vec3_type val) {
	gl_vec3_type * vd1 = ((vector3 *)v1)->data;

	vd1[0] /= val;
	vd1[1] /= val;
	vd1[2] /= val;
}

gl_vec3 v3_mult_value(gl_vec3 v1, gl_vec3_type val) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_mult_value(vc1, val);

	return vc1;
}

gl_vec3 v3_sub_value(gl_vec3 v1, gl_vec3_type val) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_sub_value(vc1, val);

	return vc1;
}

gl_vec3 v3_div_value(gl_vec3 v1, gl_vec3_type val) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_div_value(vc1, val);

	return vc1;
}

gl_vec3 v3_add_value(gl_vec3 v1, gl_vec3_type val) {
	vector3 * vc1 = v3_coppy(v1);
	v3_ch_add_value(vc1, val);

	return vc1;
}