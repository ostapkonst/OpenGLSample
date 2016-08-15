#ifndef GL_MAT4_H
#define GL_MAT4_H

typedef void * gl_mat4;
typedef float gl_mat4_type;
typedef int gl_mat4_index;

extern gl_mat4 m4_create();
extern gl_mat4 m4_create_fill(gl_mat4_type a0,  gl_mat4_type a1,  gl_mat4_type a2,  gl_mat4_type a3, 
							  gl_mat4_type a4,  gl_mat4_type a5,  gl_mat4_type a6,  gl_mat4_type a7, 
							  gl_mat4_type a8,  gl_mat4_type a9,  gl_mat4_type a10, gl_mat4_type a11,
							  gl_mat4_type a12, gl_mat4_type a13, gl_mat4_type a14, gl_mat4_type a15);
extern void m4_destroy(gl_mat4 m1);

extern void m4_ch_add(gl_mat4 m1, gl_mat4 m2);
extern void m4_ch_sub(gl_mat4 m1, gl_mat4 m2);

extern gl_mat4 m4_coppy(gl_mat4 m1);

extern gl_mat4 m4_add(gl_mat4 m1, gl_mat4 m2);
extern gl_mat4 m4_sub(gl_mat4 m1, gl_mat4 m2);

extern gl_mat4 m4_multipli(gl_mat4 m1, gl_mat4 m2);
extern gl_mat4_type m4_determ(gl_mat4 m1);
extern gl_mat4 m4_invers(gl_mat4 m1);
extern gl_mat4 m4_transp(gl_mat4 m1);

extern gl_mat4_type * m4_00(gl_mat4 m1);
extern gl_mat4_type * m4_01(gl_mat4 m1);
extern gl_mat4_type * m4_02(gl_mat4 m1);
extern gl_mat4_type * m4_03(gl_mat4 m1);
extern gl_mat4_type * m4_10(gl_mat4 m1);
extern gl_mat4_type * m4_11(gl_mat4 m1);
extern gl_mat4_type * m4_12(gl_mat4 m1);
extern gl_mat4_type * m4_13(gl_mat4 m1);
extern gl_mat4_type * m4_20(gl_mat4 m1);
extern gl_mat4_type * m4_21(gl_mat4 m1);
extern gl_mat4_type * m4_22(gl_mat4 m1);
extern gl_mat4_type * m4_23(gl_mat4 m1);
extern gl_mat4_type * m4_30(gl_mat4 m1);
extern gl_mat4_type * m4_31(gl_mat4 m1);
extern gl_mat4_type * m4_32(gl_mat4 m1);
extern gl_mat4_type * m4_33(gl_mat4 m1);

extern void m4_ch_add_value(gl_mat4 m1, gl_mat4_type val);
extern void m4_ch_mult_value(gl_mat4 m1, gl_mat4_type val);
extern void m4_ch_sub_value(gl_mat4 m1, gl_mat4_type val);
extern void m4_ch_div_value(gl_mat4 m1, gl_mat4_type val);

extern gl_mat4 m4_mult_value(gl_mat4 m1, gl_mat4_type val);
extern gl_mat4 m4_sub_value(gl_mat4 m1, gl_mat4_type val);
extern gl_mat4 m4_div_value(gl_mat4 m1, gl_mat4_type val);
extern gl_mat4 m4_add_value(gl_mat4 m1, gl_mat4_type val);

#endif