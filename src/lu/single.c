#include "lu/single.h"

#include <math.h>

// Обмен двух значений
#define _swap(x, y) { typeof(x) tmp = x; x = y; y = tmp; }

/**
 *
 * @param A Входная матрица
 * @return
 */
matrix_t* single_matrix_pivot(matrix_t* A) {
	matrix_t* R = matrix_new(A->m, A->n);
	for (int i = 0; i < A->m; i++)
		for (int j = 0; j < A->n; j++)
			R->values[i][j] = (i == j);
	for (int i = 0; i < A->m; i++) {
		int max_j = i;
		for (int j = i; j < A->n; j++) {
			if (fabs(A->values[j][i]) > fabs(A->values[max_j][i])) {
				max_j = j;
			}
		}
		if (max_j != i) {
			for (int k = 0; k < A->m; k++) {
				_swap(R->values[i][k], R->values[max_j][k]);
			}
		}
	}
	return R;
}

LU_t single_LU(matrix_t* A) {
	// Создание нижней единичной L и пустой U матриц
	matrix_t* L = matrix_identity(A->m);
	matrix_t* U = matrix_new(A->m, A->n);
	// Создание ступенчатой ??? матрицы R
	matrix_t* R = single_matrix_pivot(A);
	matrix_t* Aprime = matrix_multiply(R, A);
	//
	for (int i = 0; i < A->n; i++) {
		for (int j = 0; j < A->n; j++) {
			double s;
			if (j <= i) {
				s = 0.0;
				for (int k = 0; k < j; k++)
					s += L->values[j][k] * U->values[k][i];
				U->values[j][i] = Aprime->values[j][i] - s;
			}
			if (j >= i) {
				s = 0.0;
				for (int k = 0; k < i; k++)
					s += L->values[j][k] * U->values[k][i];
				L->values[j][i] = (Aprime->values[j][i] - s) / U->values[i][i];
			}
		}
	}
	// Удаление
	matrix_delete(Aprime);
	// Выдача результата
	LU_t result;
	result.L = L;
	result.U = U;
	return result;
}
