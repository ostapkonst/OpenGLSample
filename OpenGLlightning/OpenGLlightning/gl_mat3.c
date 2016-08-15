#include "gl_mat3.h"
#include <stdlib.h>
#include <math.h>

typedef struct {
	gl_mat3_type data[9];
} matrix3;

gl_mat3 m3_create() {
	return malloc(sizeof(matrix3));
}

gl_mat3 m3_create_fill(gl_mat3_type a0, gl_mat3_type a1, gl_mat3_type a2, 
							  gl_mat3_type a3, gl_mat3_type a4, gl_mat3_type a5, 
							  gl_mat3_type a6, gl_mat3_type a7, gl_mat3_type a8) {
	matrix3 * mr1 = m3_create();
	gl_mat3_type * dm1 = mr1->data;

	dm1[0] = a0; dm1[1] = a1; dm1[2] = a2;
	dm1[3] = a3; dm1[4] = a4; dm1[5] = a5;
	dm1[6] = a6; dm1[7] = a7; dm1[8] = a8;

	return mr1;
}

void m3_destroy(gl_mat3 m1) {
	free(m1);
}

void m3_ch_add(gl_mat3 m1, gl_mat3 m2) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;
	gl_mat3_type * dm2 = ((matrix3 *)m2)->data;

	dm1[0] += dm2[0]; dm1[1] += dm2[1]; dm1[2] += dm2[2];
	dm1[3] += dm2[3]; dm1[4] += dm2[4]; dm1[5] += dm2[5];
	dm1[6] += dm2[6]; dm1[7] += dm2[7]; dm1[8] += dm2[8];
}
void m3_ch_sub(gl_mat3 m1, gl_mat3 m2) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;
	gl_mat3_type * dm2 = ((matrix3 *)m2)->data;

	dm1[0] -= dm2[0]; dm1[1] -= dm2[1]; dm1[2] -= dm2[2];
	dm1[3] -= dm2[3]; dm1[4] -= dm2[4]; dm1[5] -= dm2[5];
	dm1[6] -= dm2[6]; dm1[7] -= dm2[7]; dm1[8] -= dm2[8];
}

gl_mat3 m3_coppy(gl_mat3 m1) {
	gl_mat3_type * dm2 = ((matrix3 *)m1)->data;

	return m3_create_fill(
		   dm2[0], dm2[1], dm2[2],
		   dm2[3], dm2[4], dm2[5],
		   dm2[6], dm2[7], dm2[8]);
}

gl_mat3 m3_add(gl_mat3 m1, gl_mat3 m2) {
	matrix3 * mr1 = m3_coppy(m1);
	m3_ch_add(mr1, m2);

	return mr1;
}
gl_mat3 m3_sub(gl_mat3 m1, gl_mat3 m2) {
	matrix3 * mr1 = m3_coppy(m1);
	m3_ch_sub(mr1, m2);

	return mr1;
}

gl_mat3 m3_multipli(gl_mat3 m1, gl_mat3 m2) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;
	gl_mat3_type * dm2 = ((matrix3 *)m2)->data;

	return m3_create_fill(
		   dm1[0] * dm2[0] + dm1[1] * dm2[3] + dm1[2] * dm2[6],
		   dm1[0] * dm2[1] + dm1[1] * dm2[4] + dm1[2] * dm2[7],
		   dm1[0] * dm2[2] + dm1[1] * dm2[5] + dm1[2] * dm2[8],
		   dm1[3] * dm2[0] + dm1[4] * dm2[3] + dm1[5] * dm2[6],
		   dm1[3] * dm2[1] + dm1[4] * dm2[4] + dm1[5] * dm2[7],
		   dm1[3] * dm2[2] + dm1[4] * dm2[5] + dm1[5] * dm2[8],
		   dm1[6] * dm2[0] + dm1[7] * dm2[3] + dm1[8] * dm2[6],
		   dm1[6] * dm2[1] + dm1[7] * dm2[4] + dm1[8] * dm2[7],
		   dm1[6] * dm2[2] + dm1[7] * dm2[5] + dm1[8] * dm2[8]);

}

gl_mat3_type m3_determ(gl_mat3 m1) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;

	return dm1[0] * (dm1[4] * dm1[8] - dm1[5] * dm1[7]) -
		   dm1[1] * (dm1[3] * dm1[8] - dm1[5] * dm1[6]) +
		   dm1[2] * (dm1[3] * dm1[7] - dm1[4] * dm1[6]);
}

gl_mat3 m3_invers(gl_mat3 m1) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;
	gl_mat3_type det = 1.0f / m3_determ(m1);

	return m3_create_fill(
		   (dm1[4] * dm1[8] - dm1[5] * dm1[7]) * det,
		   (dm1[2] * dm1[7] - dm1[1] * dm1[8]) * det,
		   (dm1[1] * dm1[5] - dm1[2] * dm1[4]) * det,
		   (dm1[5] * dm1[6] - dm1[3] * dm1[8]) * det,
		   (dm1[0] * dm1[8] - dm1[2] * dm1[6]) * det,
		   (dm1[2] * dm1[3] - dm1[0] * dm1[5]) * det,
		   (dm1[3] * dm1[7] - dm1[4] * dm1[6]) * det,
		   (dm1[1] * dm1[6] - dm1[0] * dm1[7]) * det,
		   (dm1[0] * dm1[4] - dm1[1] * dm1[3]) * det);
}

gl_mat3 m3_transp(gl_mat3 m1) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;

	return m3_create_fill(
		   dm1[0], dm1[3], dm1[6],
		   dm1[1], dm1[4], dm1[7],
		   dm1[2], dm1[5], dm1[8]);
}

gl_mat3_type * m3_00(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[0];
}
gl_mat3_type * m3_01(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[1];
}
gl_mat3_type * m3_02(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[2];
}
gl_mat3_type * m3_10(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[3];
}
gl_mat3_type * m3_11(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[4];
}
gl_mat3_type * m3_12(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[5];
}
gl_mat3_type * m3_20(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[6];
}
gl_mat3_type * m3_21(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[7];
}
gl_mat3_type * m3_22(gl_mat3 m1) {
	return &((matrix3 *)m1)->data[8];
}

void m3_ch_add_value(gl_mat3 m1, gl_mat3_type val) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;

	dm1[0] += val; dm1[1] += val; dm1[2] += val;
	dm1[3] += val; dm1[4] += val; dm1[5] += val;
	dm1[6] += val; dm1[7] += val; dm1[8] += val;
}

void m3_ch_mult_value(gl_mat3 m1, gl_mat3_type val) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;

	dm1[0] *= val; dm1[1] *= val; dm1[2] *= val;
	dm1[3] *= val; dm1[4] *= val; dm1[5] *= val;
	dm1[6] *= val; dm1[7] *= val; dm1[8] *= val;
}

void m3_ch_sub_value(gl_mat3 m1, gl_mat3_type val) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;

	dm1[0] -= val; dm1[1] -= val; dm1[2] -= val;
	dm1[3] -= val; dm1[4] -= val; dm1[5] -= val;
	dm1[6] -= val; dm1[7] -= val; dm1[8] -= val;
}

void m3_ch_div_value(gl_mat3 m1, gl_mat3_type val) {
	gl_mat3_type * dm1 = ((matrix3 *)m1)->data;

	dm1[0] /= val; dm1[1] /= val; dm1[2] /= val;
	dm1[3] /= val; dm1[4] /= val; dm1[5] /= val;
	dm1[6] /= val; dm1[7] /= val; dm1[8] /= val;
}

gl_mat3 m3_mult_value(gl_mat3 m1, gl_mat3_type val) {
	matrix3 * mr1 = m3_coppy(m1);
	m3_ch_mult_value(mr1, val);

	return mr1;
}

gl_mat3 m3_sub_value(gl_mat3 m1, gl_mat3_type val) {
	matrix3 * mr1 = m3_coppy(m1);
	m3_ch_sub_value(mr1, val);

	return mr1;
}

gl_mat3 m3_div_value(gl_mat3 m1, gl_mat3_type val) {
	matrix3 * mr1 = m3_coppy(m1);
	m3_ch_div_value(mr1, val);

	return mr1;
}

gl_mat3 m3_add_value(gl_mat3 m1, gl_mat3_type val) {
	matrix3 * mr1 = m3_coppy(m1);
	m3_ch_add_value(mr1, val);

	return mr1;
}