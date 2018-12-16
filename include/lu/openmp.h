#ifndef LUMD_OMP_H
#define LUMD_OMP_H

#include "lu.h"

/**
 * OpenMP LU matrix decomposition
 * @param matrix matrix
 * @return result
 */
LU_t omp_LU(matrix_t* matrix);

#endif //LUMD_OMP_H
