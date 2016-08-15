#ifndef GL_MAT3_H
#define GL_MAT3_H

typedef void * gl_mat3;
typedef float gl_mat3_type;
typedef int gl_mat3_index;

extern gl_mat3 m3_create();
extern gl_mat3 m3_create_fill(gl_mat3_type a0, gl_mat3_type a1, gl_mat3_type a2, 
							  gl_mat3_type a3, gl_mat3_type a4, gl_mat3_type a5, 
							  gl_mat3_type a6, gl_mat3_type a7, gl_mat3_type a8);
extern void m3_destroy(gl_mat3 ah);

extern void m3_ch_add(gl_mat3 m1, gl_mat3 m2);
extern void m3_ch_sub(gl_mat3 m1, gl_mat3 m2);

extern gl_mat3 m3_coppy(gl_mat3 m1);

extern gl_mat3 m3_add(gl_mat3 m1, gl_mat3 m2);
extern gl_mat3 m3_sub(gl_mat3 m1, gl_mat3 m2);

extern gl_mat3 m3_multipli(gl_mat3 m1, gl_mat3 m2);
extern gl_mat3_type m3_determ(gl_mat3 m1);
extern gl_mat3 m3_invers(gl_mat3 m1);
extern gl_mat3 m3_transp(gl_mat3 m1);

extern gl_mat3_type * m3_00(gl_mat3 m1);
extern gl_mat3_type * m3_01(gl_mat3 m1);
extern gl_mat3_type * m3_02(gl_mat3 m1);
extern gl_mat3_type * m3_10(gl_mat3 m1);
extern gl_mat3_type * m3_11(gl_mat3 m1);
extern gl_mat3_type * m3_12(gl_mat3 m1);
extern gl_mat3_type * m3_20(gl_mat3 m1);
extern gl_mat3_type * m3_21(gl_mat3 m1);
extern gl_mat3_type * m3_22(gl_mat3 m1);

extern void m3_ch_add_value(gl_mat3 m1, gl_mat3_type val);
extern void m3_ch_mult_value(gl_mat3 m1, gl_mat3_type val);
extern void m3_ch_sub_value(gl_mat3 m1, gl_mat3_type val);
extern void m3_ch_div_value(gl_mat3 m1, gl_mat3_type val);

extern gl_mat3 m3_mult_value(gl_mat3 m1, gl_mat3_type val);
extern gl_mat3 m3_sub_value(gl_mat3 m1, gl_mat3_type val);
extern gl_mat3 m3_div_value(gl_mat3 m1, gl_mat3_type val);
extern gl_mat3 m3_add_value(gl_mat3 m1, gl_mat3_type val);

#endif