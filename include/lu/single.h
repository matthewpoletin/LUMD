/**
 * Однопоточное LU разложение матрицы
 * @file single.h
 * @author matthewpoletin
 */

#ifndef LUDM_SINGLE_H
#define LUDM_SINGLE_H

#include "matrix.h"
#include "lu/lu.h"

/**
 * Однопоточное LU разложение матрицы
 * @param matrix Матрица для разложения
 * @return Резултат LU разложения
 */
LU_t single_LU(matrix_t* matrix);

#endif //LUDM_SINGLE_H
