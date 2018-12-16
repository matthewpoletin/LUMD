#ifndef LUMD_MPI_H
#define LUMD_MPI_H

#include "lu.h"

/**
 * MPI LU matrix decomposition
 * @param matrix matrix
 * @return result
 */
LU_t mpi_LU(matrix_t* matrix);

#endif //LUMD_MPI_H
