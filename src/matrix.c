#include <stdlib.h>
#include "matrix.h"

matrix_t* matrix_create(double** values, int m, int n) {
	matrix_t* matrix = malloc(sizeof(matrix_t));
	matrix->m = m;
	matrix->n = n;
	matrix->values = values;
	return matrix;
}
