#ifndef GL_VEC3_H
#define GL_VEC3_H

typedef void * gl_vec3;
typedef float gl_vec3_type;
typedef int gl_vec3_index;

extern gl_vec3 v3_create();
extern gl_vec3 v3_create_fill(gl_vec3_type x, gl_vec3_type y, gl_vec3_type z);
extern void v3_destroy(gl_vec3 v1);

extern void v3_ch_add(gl_vec3 v1, gl_vec3 v2);
extern void v3_ch_mult(gl_vec3 v1, gl_vec3 v2);
extern void v3_ch_sub(gl_vec3 v1, gl_vec3 v2);
extern void v3_ch_div(gl_vec3 v1, gl_vec3 v2);

extern gl_vec3 v3_coppy(gl_vec3 v1);

extern gl_vec3 v3_mult(gl_vec3 v1, gl_vec3 v2);
extern gl_vec3 v3_sub(gl_vec3 v1, gl_vec3 v2);
extern gl_vec3 v3_div(gl_vec3 v1, gl_vec3 v2);
extern gl_vec3 v3_add(gl_vec3 v1, gl_vec3 v2);

extern gl_vec3_type v3_dot(gl_vec3 v1, gl_vec3 v2);
extern gl_vec3 v3_cross(gl_vec3 v1,gl_vec3 v2);
extern gl_vec3_type v3_len(gl_vec3 vc1);
extern gl_vec3_type v3_dist(gl_vec3 v1, gl_vec3 v2);
extern gl_vec3 v3_norm(gl_vec3 v1);

extern gl_vec3_type * v3_x(gl_vec3 v1);
extern gl_vec3_type * v3_y(gl_vec3 v1);
extern gl_vec3_type * v3_z(gl_vec3 v1);

extern void v3_ch_add_value(gl_vec3 v1, gl_vec3_type val);
extern void v3_ch_mult_value(gl_vec3 v1, gl_vec3_type val);
extern void v3_ch_sub_value(gl_vec3 v1, gl_vec3_type val);
extern void v3_ch_div_value(gl_vec3 v1, gl_vec3_type val);

extern gl_vec3 v3_mult_value(gl_vec3 v1, gl_vec3_type val);
extern gl_vec3 v3_sub_value(gl_vec3 v1, gl_vec3_type val);
extern gl_vec3 v3_div_value(gl_vec3 v1, gl_vec3_type val);
extern gl_vec3 v3_add_value(gl_vec3 v1, gl_vec3_type val);

#endif