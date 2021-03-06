#include "lu/single.h"

#include <math.h>

#include "common.h"

LU_t single_LU(matrix_t* matrix) {
	int m = (int) matrix->m;
	int n = (int) matrix->n;
	// Создание нижней единичной L и пустой U матриц
	double* l = malloc(sizeof(double) * m * n);
	double* u = malloc(sizeof(double) * m * n);
	double* A = matrix_to_array(matrix);
	int i, j, k, z, flag = 0;
	for (i = 0; i < n; i++) {
		array_set(l, n, i + 1, i + 1, 1.0);
		double sum_u = 0.0, sum_l = 0.0;
		for (k = 0; k < i; k++) {
			sum_u += array_get(u, n, k + 1, i + 1) * array_get(l, n, i + 1, k + 1);
		}
		array_set(u, n, i + 1, i + 1, (array_get(A, n, i + 1, i + 1) - sum_u));
		for (j = 0; j < 2 * (n - i - 1); j++) {
			if (j < n - i - 1) {
				sum_u = 0.0;
				for (k = 0; k < i; k++) {
					sum_u += array_get(u, n, k + 1, j + i + 2) * array_get(l, n, i + 1, k + 1);
				}
				array_set(u, n, i + 1, j + i + 2, (array_get(A, n, i + 1, j + i + 2) - sum_u));
			} else {
				z = j % (n - i - 1);
				sum_l = 0.0;
				for (k = 0; k < i; k++) {
					sum_l += array_get(u, n, k + 1, i + 1) * array_get(l, n, z + i + 2, k + 1);
				}
				double divd = array_get(u, n, i + 1, i + 1);
				if (divd == 0.0)
					flag = -1;
				array_set(l, n, z + i + 2, i + 1, (array_get(A, n, z + i + 2, i + 1) - sum_l) / divd);
			}
		}
	}
	// Выдача результата
	LU_t result;
	result.L = matrix_create((size_t) m, (size_t) n, l);
	result.U = matrix_create((size_t) m, (size_t) n, u);
	// Очистка промежуточных значений
	free(l);
	free(u);
	free(A);
	return result;
}
