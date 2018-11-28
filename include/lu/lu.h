#ifndef LUDM_LU_H
#define LUDM_LU_H

#include "matrix.h"

/**
 * Результат LU разложения матрицы
 */
typedef struct {
	// Матрица L
	matrix_t L;
	// Матрица U
	matrix_t U;
} LU_t;

#endif //LUDM_LU_H
