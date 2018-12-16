#ifndef LUDM_LU_H
#define LUDM_LU_H

#include "matrix.h"

/**
 * Результат LU разложения матрицы
 */
typedef struct {
	// Нижняя треугольная матрица
	matrix_t* L;
	// Верхняя треугольная матрица с единичной диагональю
	matrix_t* U;
} LU_t;

#endif //LUDM_LU_H
