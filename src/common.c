#include "common.h"

double array_get(double* M, int n, int i, int j) {
	return M[(i - 1) * n + j - 1];
}

void array_set(double* M, int n, int i, int j, double val) {
	M[(i - 1) * n + j - 1] = val;
}

double* matrix_to_array(matrix_t* matrix) {
	double* result = malloc(sizeof(double) * matrix->m * matrix->n);
	for (int i = 0; i < matrix->m; i++)
		for (int j = 0; j < matrix->n; j++)
			result[i * matrix->n + j] = matrix->values[i][j];
	return result;
}
