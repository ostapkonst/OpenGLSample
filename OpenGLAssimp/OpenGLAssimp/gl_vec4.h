#ifndef GL_VEC4_H
#define GL_VEC4_H

typedef void * gl_vec4;
typedef float gl_vec4_type;
typedef int gl_vec4_index;

extern gl_vec4 v4_create();
extern gl_vec4 v4_create_fill(gl_vec4_type x, gl_vec4_type y, gl_vec4_type z, gl_vec4_type w);
extern void v4_destroy(gl_vec4 v1);

extern void v4_ch_add(gl_vec4 v1, gl_vec4 v2);
extern void v4_ch_mult(gl_vec4 v1, gl_vec4 v2);
extern void v4_ch_sub(gl_vec4 v1, gl_vec4 v2);
extern void v4_ch_div(gl_vec4 v1, gl_vec4 v2);

extern gl_vec4 v4_coppy(gl_vec4 v1);

extern gl_vec4 v4_mult(gl_vec4 v1, gl_vec4 v2);
extern gl_vec4 v4_sub(gl_vec4 v1, gl_vec4 v2);
extern gl_vec4 v4_div(gl_vec4 v1, gl_vec4 v2);
extern gl_vec4 v4_add(gl_vec4 v1, gl_vec4 v2);

extern gl_vec4_type v4_dot(gl_vec4 v1, gl_vec4 v2);
extern gl_vec4_type v4_len(gl_vec4 vc1);
extern gl_vec4_type v4_dist(gl_vec4 v1, gl_vec4 v2);
extern gl_vec4 v4_norm(gl_vec4 v1);

extern gl_vec4_type * v4_x(gl_vec4 v1);
extern gl_vec4_type * v4_y(gl_vec4 v1);
extern gl_vec4_type * v4_z(gl_vec4 v1);
extern gl_vec4_type * v4_w(gl_vec4 v1);

extern void v4_ch_add_value(gl_vec4 v1, gl_vec4_type val);
extern void v4_ch_mult_value(gl_vec4 v1, gl_vec4_type val);
extern void v4_ch_sub_value(gl_vec4 v1, gl_vec4_type val);
extern void v4_ch_div_value(gl_vec4 v1, gl_vec4_type val);

extern gl_vec4 v4_mult_value(gl_vec4 v1, gl_vec4_type val);
extern gl_vec4 v4_sub_value(gl_vec4 v1, gl_vec4_type val);
extern gl_vec4 v4_div_value(gl_vec4 v1, gl_vec4_type val);
extern gl_vec4 v4_add_value(gl_vec4 v1, gl_vec4_type val);

#endif