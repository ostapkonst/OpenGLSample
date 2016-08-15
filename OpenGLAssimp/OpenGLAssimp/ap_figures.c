#include "ap_figures.h"
#include <stdlib.h>

void * Figure_Grid(float pos_x, float pos_y, float pos_z, 
				   int size, float step) {
	float * arr = malloc(sizeof(float) * size * 12);
	int count = 0;
	int i;

	for (i = 0; i < size; i++) {
		arr[count++] = pos_x + i * step;
		arr[count++] = pos_y;
		arr[count++] = pos_z;

		arr[count++] = pos_x + i * step;
		arr[count++] = pos_y;
		arr[count++] = pos_z + step * (size - 1);

		arr[count++] = pos_x;
		arr[count++] = pos_y;
		arr[count++] = pos_z + i * step;

		arr[count++] = pos_x + step * (size - 1);
		arr[count++] = pos_y;
		arr[count++] = pos_z + i * step;
	}

	return arr;
}