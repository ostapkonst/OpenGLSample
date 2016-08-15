#include "gl_mat4.h"
#include <stdlib.h>
#include <math.h>

typedef struct {
	gl_mat4_type data[16];
} matrix4;

gl_mat4 m4_create() {
	return malloc(sizeof(matrix4));
}

gl_mat4 m4_create_fill(gl_mat4_type a0,  gl_mat4_type a1,  gl_mat4_type a2,  gl_mat4_type a3, 
					   gl_mat4_type a4,  gl_mat4_type a5,  gl_mat4_type a6,  gl_mat4_type a7, 
					   gl_mat4_type a8,  gl_mat4_type a9,  gl_mat4_type a10, gl_mat4_type a11,
					   gl_mat4_type a12, gl_mat4_type a13, gl_mat4_type a14, gl_mat4_type a15) {
	matrix4 * mr1 = m4_create();
	gl_mat4_type * dm1 = mr1->data;

	dm1[0 ] = a0;  dm1[1 ] = a1;  dm1[2 ] = a2;  dm1[3 ] = a3; 
	dm1[4 ] = a4;  dm1[5 ] = a5;  dm1[6 ] = a6;  dm1[7 ] = a7; 
	dm1[8 ] = a8;  dm1[9 ] = a9;  dm1[10] = a10; dm1[11] = a11; 
	dm1[12] = a12; dm1[13] = a13; dm1[14] = a14; dm1[15] = a15; 

	return mr1;
}

void m4_destroy(gl_mat4 m1) {
	free(m1);
}

void m4_ch_add(gl_mat4 m1, gl_mat4 m2) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;
	gl_mat4_type * dm2 = ((matrix4 *)m2)->data;

	dm1[0 ] += dm2[0 ]; dm1[1 ] += dm2[1 ]; dm1[2 ] += dm2[2 ]; dm1[3 ] += dm2[3 ]; 
	dm1[4 ] += dm2[4 ]; dm1[5 ] += dm2[5 ];	dm1[6 ] += dm2[6 ]; dm1[7 ] += dm2[7 ]; 
	dm1[8 ] += dm2[8 ]; dm1[9 ] += dm2[9 ];	dm1[10] += dm2[10]; dm1[11] += dm2[11]; 
	dm1[12] += dm2[12]; dm1[13] += dm2[13];	dm1[14] += dm2[14]; dm1[15] += dm2[15];
}
void m4_ch_sub(gl_mat4 m1, gl_mat4 m2) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;
	gl_mat4_type * dm2 = ((matrix4 *)m2)->data;

	dm1[0 ] -= dm2[0 ]; dm1[1 ] -= dm2[1 ]; dm1[2 ] -= dm2[2 ]; dm1[3 ] -= dm2[3 ]; 
	dm1[4 ] -= dm2[4 ]; dm1[5 ] -= dm2[5 ];	dm1[6 ] -= dm2[6 ]; dm1[7 ] -= dm2[7 ]; 
	dm1[8 ] -= dm2[8 ]; dm1[9 ] -= dm2[9 ];	dm1[10] -= dm2[10]; dm1[11] -= dm2[11]; 
	dm1[12] -= dm2[12]; dm1[13] -= dm2[13];	dm1[14] -= dm2[14]; dm1[15] -= dm2[15];
}

gl_mat4 m4_coppy(gl_mat4 m1) {
	gl_mat4_type * dm2 = ((matrix4 *)m1)->data;

	return m4_create_fill(
		   dm2[0 ], dm2[1 ], dm2[2 ], dm2[3 ], 
		   dm2[4 ], dm2[5 ], dm2[6 ], dm2[7 ],
		   dm2[8 ], dm2[9 ], dm2[10], dm2[11],
		   dm2[12], dm2[13], dm2[14], dm2[15]);
}

gl_mat4 m4_add(gl_mat4 m1, gl_mat4 m2) {
	matrix4 * mr1 = m4_coppy(m1);
	m4_ch_add(mr1, m2);

	return mr1;
}
gl_mat4 m4_sub(gl_mat4 m1, gl_mat4 m2) {
	matrix4 * mr1 = m4_coppy(m1);
	m4_ch_sub(mr1, m2);

	return mr1;
}

gl_mat4 m4_multipli(gl_mat4 m1, gl_mat4 m2) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;
	gl_mat4_type * dm2 = ((matrix4 *)m2)->data;

	return m4_create_fill(
		   dm1[0 ] * dm2[0] + dm1[1 ] * dm2[4] + dm1[2 ] * dm2[8 ] + dm1[3 ] * dm2[12],
		   dm1[0 ] * dm2[1] + dm1[1 ] * dm2[5] + dm1[2 ] * dm2[9 ] + dm1[3 ] * dm2[13],
		   dm1[0 ] * dm2[2] + dm1[1 ] * dm2[6] + dm1[2 ] * dm2[10] + dm1[3 ] * dm2[14],
		   dm1[0 ] * dm2[3] + dm1[1 ] * dm2[7] + dm1[2 ] * dm2[11] + dm1[3 ] * dm2[15],
		   dm1[4 ] * dm2[0] + dm1[5 ] * dm2[4] + dm1[6 ] * dm2[8 ] + dm1[7 ] * dm2[12],
		   dm1[4 ] * dm2[1] + dm1[5 ] * dm2[5] + dm1[6 ] * dm2[9 ] + dm1[7 ] * dm2[13],
		   dm1[4 ] * dm2[2] + dm1[5 ] * dm2[6] + dm1[6 ] * dm2[10] + dm1[7 ] * dm2[14],
		   dm1[4 ] * dm2[3] + dm1[5 ] * dm2[7] + dm1[6 ] * dm2[11] + dm1[7 ] * dm2[15],
		   dm1[8 ] * dm2[0] + dm1[9 ] * dm2[4] + dm1[10] * dm2[8 ] + dm1[11] * dm2[12],
		   dm1[8 ] * dm2[1] + dm1[9 ] * dm2[5] + dm1[10] * dm2[9 ] + dm1[11] * dm2[13],
		   dm1[8 ] * dm2[2] + dm1[9 ] * dm2[6] + dm1[10] * dm2[10] + dm1[11] * dm2[14],
		   dm1[8 ] * dm2[3] + dm1[9 ] * dm2[7] + dm1[10] * dm2[11] + dm1[11] * dm2[15],
		   dm1[12] * dm2[0] + dm1[13] * dm2[4] + dm1[14] * dm2[8 ] + dm1[15] * dm2[12],
		   dm1[12] * dm2[1] + dm1[13] * dm2[5] + dm1[14] * dm2[9 ] + dm1[15] * dm2[13],
		   dm1[12] * dm2[2] + dm1[13] * dm2[6] + dm1[14] * dm2[10] + dm1[15] * dm2[14],
		   dm1[12] * dm2[3] + dm1[13] * dm2[7] + dm1[14] * dm2[11] + dm1[15] * dm2[15]);
}

gl_mat4_type m4_determ(gl_mat4 m1) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;
	gl_mat4_type A, B, C, D, E, F;

	A = dm1[10] * dm1[15] - dm1[11] * dm1[14];
	B = dm1[ 9] * dm1[15] - dm1[11] * dm1[13];
	C = dm1[ 9] * dm1[14] - dm1[10] * dm1[13];
	D = dm1[ 8] * dm1[15] - dm1[11] * dm1[12];
	E = dm1[ 8] * dm1[14] - dm1[10] * dm1[12];
	F = dm1[ 8] * dm1[13] - dm1[ 9] * dm1[12];

	return dm1[0] * (A * dm1[5] - B * dm1[6] + C * dm1[7]) -
		   dm1[1] * (A * dm1[4] - D * dm1[6] + E * dm1[7]) +
		   dm1[2] * (B * dm1[4] - D * dm1[5] + F * dm1[7]) -
		   dm1[3] * (C * dm1[4] - E * dm1[5] + F * dm1[6]);
}

gl_mat4 m4_invers(gl_mat4 m1) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;
	gl_mat4_type det = 1.0f / m4_determ(m1);

	#define MDET3(a0,a1,a2,a3,a4,a5,a6,a7,a8) \
				 (a0 * (a4 * a8 - a5 * a7) -  \
				  a1 * (a3 * a8 - a5 * a6) +  \
				  a2 * (a3 * a7 - a4 * a6)	)

	return m4_create_fill(
		 MDET3(dm1[5], dm1[6], dm1[7], dm1[9], dm1[10], dm1[11], dm1[13], dm1[14], dm1[15]) * det,
		-MDET3(dm1[1], dm1[2], dm1[3], dm1[9], dm1[10], dm1[11], dm1[13], dm1[14], dm1[15]) * det,
		 MDET3(dm1[1], dm1[2], dm1[3], dm1[5], dm1[ 6], dm1[ 7], dm1[13], dm1[14], dm1[15]) * det,
		-MDET3(dm1[1], dm1[2], dm1[3], dm1[5], dm1[ 6], dm1[ 7], dm1[ 9], dm1[10], dm1[11]) * det,
		-MDET3(dm1[4], dm1[6], dm1[7], dm1[8], dm1[10], dm1[11], dm1[12], dm1[14], dm1[15]) * det,
		 MDET3(dm1[0], dm1[2], dm1[3], dm1[8], dm1[10], dm1[11], dm1[12], dm1[14], dm1[15]) * det,
		-MDET3(dm1[0], dm1[2], dm1[3], dm1[4], dm1[ 6], dm1[ 7], dm1[12], dm1[14], dm1[15]) * det,
		 MDET3(dm1[0], dm1[2], dm1[3], dm1[4], dm1[ 6], dm1[ 7], dm1[ 8], dm1[10], dm1[11]) * det,
		 MDET3(dm1[4], dm1[5], dm1[7], dm1[8], dm1[ 9], dm1[11], dm1[12], dm1[13], dm1[15]) * det,
		-MDET3(dm1[0], dm1[1], dm1[3], dm1[8], dm1[ 9], dm1[11], dm1[12], dm1[13], dm1[15]) * det,
		 MDET3(dm1[0], dm1[1], dm1[3], dm1[4], dm1[ 5], dm1[ 7], dm1[12], dm1[13], dm1[15]) * det,
		-MDET3(dm1[0], dm1[1], dm1[3], dm1[4], dm1[ 5], dm1[ 7], dm1[ 8], dm1[ 9], dm1[11]) * det,
		-MDET3(dm1[4], dm1[5], dm1[6], dm1[8], dm1[ 9], dm1[10], dm1[12], dm1[13], dm1[14]) * det,
		 MDET3(dm1[0], dm1[1], dm1[2], dm1[8], dm1[ 9], dm1[10], dm1[12], dm1[13], dm1[14]) * det,
		-MDET3(dm1[0], dm1[1], dm1[2], dm1[4], dm1[ 5], dm1[ 6], dm1[12], dm1[13], dm1[14]) * det,
		 MDET3(dm1[0], dm1[1], dm1[2], dm1[4], dm1[ 5], dm1[ 6], dm1[ 8], dm1[ 9], dm1[10]) * det);
}

gl_mat4 m4_transp(gl_mat4 m1) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;

	return m4_create_fill(
		   dm1[0], dm1[4], dm1[ 8], dm1[12],
		   dm1[1], dm1[5], dm1[ 9], dm1[13],
		   dm1[2], dm1[6], dm1[10], dm1[14],
		   dm1[3], dm1[7], dm1[11], dm1[15]);
}

gl_mat4_type * m4_00(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[0];
}
gl_mat4_type * m4_01(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[1];
}
gl_mat4_type * m4_02(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[2];
}
gl_mat4_type * m4_03(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[3];
}
gl_mat4_type * m4_10(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[4];
}
gl_mat4_type * m4_11(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[5];
}
gl_mat4_type * m4_12(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[6];
}
gl_mat4_type * m4_13(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[7];
}
gl_mat4_type * m4_20(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[8];
}
gl_mat4_type * m4_21(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[9];
}
gl_mat4_type * m4_22(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[10];
}
gl_mat4_type * m4_23(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[11];
}
gl_mat4_type * m4_30(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[12];
}
gl_mat4_type * m4_31(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[13];
}
gl_mat4_type * m4_32(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[14];
}
gl_mat4_type * m4_33(gl_mat4 m1) {
	return &((matrix4 *)m1)->data[15];
}

void m4_ch_add_value(gl_mat4 m1, gl_mat4_type val) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;

	dm1[ 0] += val; dm1[ 1] += val; dm1[ 2] += val; dm1[ 3] += val; 
	dm1[ 4] += val; dm1[ 5] += val; dm1[ 6] += val; dm1[ 7] += val; 
	dm1[ 8] += val; dm1[ 9] += val; dm1[10] += val; dm1[11] += val;
	dm1[12] += val; dm1[13] += val; dm1[14] += val; dm1[15] += val; 
}

void m4_ch_mult_value(gl_mat4 m1, gl_mat4_type val) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;

	dm1[ 0] *= val; dm1[ 1] *= val; dm1[ 2] *= val; dm1[ 3] *= val; 
	dm1[ 4] *= val; dm1[ 5] *= val; dm1[ 6] *= val; dm1[ 7] *= val; 
	dm1[ 8] *= val; dm1[ 9] *= val; dm1[10] *= val; dm1[11] *= val;
	dm1[12] *= val; dm1[13] *= val; dm1[14] *= val; dm1[15] *= val; 
}

void m4_ch_sub_value(gl_mat4 m1, gl_mat4_type val) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;

	dm1[ 0] -= val; dm1[ 1] -= val; dm1[ 2] -= val; dm1[ 3] -= val; 
	dm1[ 4] -= val; dm1[ 5] -= val; dm1[ 6] -= val; dm1[ 7] -= val; 
	dm1[ 8] -= val; dm1[ 9] -= val; dm1[10] -= val; dm1[11] -= val;
	dm1[12] -= val; dm1[13] -= val; dm1[14] -= val; dm1[15] -= val; 
}

void m4_ch_div_value(gl_mat4 m1, gl_mat4_type val) {
	gl_mat4_type * dm1 = ((matrix4 *)m1)->data;

	dm1[ 0] /= val; dm1[ 1] /= val; dm1[ 2] /= val; dm1[ 3] /= val; 
	dm1[ 4] /= val; dm1[ 5] /= val; dm1[ 6] /= val; dm1[ 7] /= val; 
	dm1[ 8] /= val; dm1[ 9] /= val; dm1[10] /= val; dm1[11] /= val;
	dm1[12] /= val; dm1[13] /= val; dm1[14] /= val; dm1[15] /= val; 
}

gl_mat4 m4_mult_value(gl_mat4 m1, gl_mat4_type val) {
	matrix4 * mr1 = m4_coppy(m1);
	m4_ch_mult_value(mr1, val);

	return mr1;
}

gl_mat4 m4_sub_value(gl_mat4 m1, gl_mat4_type val) {
	matrix4 * mr1 = m4_coppy(m1);
	m4_ch_sub_value(mr1, val);

	return mr1;
}

gl_mat4 m4_div_value(gl_mat4 m1, gl_mat4_type val) {
	matrix4 * mr1 = m4_coppy(m1);
	m4_ch_div_value(mr1, val);

	return mr1;
}

gl_mat4 m4_add_value(gl_mat4 m1, gl_mat4_type val) {
	matrix4 * mr1 = m4_coppy(m1);
	m4_ch_add_value(mr1, val);

	return mr1;
}