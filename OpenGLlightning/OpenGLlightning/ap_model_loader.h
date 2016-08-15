#ifndef AP_MODEL_LODER_H
#define AP_MODEL_LODER_H

extern void Load_Model(
	char * file_name, 
	unsigned int ** indices,
	float ** vertices,
	float ** uvs,
	float ** normals, 
	int * mod_size,
	int * ind_size
);

#endif