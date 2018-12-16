#include <gtest/gtest.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include "matrix.h"

#ifdef __cplusplus
}
#endif

TEST(matrix, matrix_cmp_zeros) {
	// Arrange
	matrix_t* matrix_a = matrix_new(2, 2);
	matrix_t* matrix_b = matrix_new(2, 2);

	// Act
	int actual_result = matrix_cmp(matrix_a, matrix_b);

	// Assert
	ASSERT_EQ(actual_result, 0);
}

TEST(matrix, matrix_cmp_values_same) {
	// Arrange
	double values[][3] = {{1.0, 3.0, 5.0},
						  {2.0, 4.0, 7.0},
						  {1.0, 1.0, 0.0}};
	matrix_t* matrix_a = matrix_create(3, 3, (double*) values);
	matrix_t* matrix_b = matrix_create(3, 3, (double*) values);

	// Act
	int actual_result = matrix_cmp(matrix_a, matrix_b);

	// Assert
	ASSERT_EQ(actual_result, 0);
}

TEST(matrix, matrix_cmp_values_diff) {
	// Arrange
	double values_a[][3] = {{1.0, 3.0, 5.0},
							{2.0, 4.0, 7.0},
							{1.0, 1.0, 0.0}};
	matrix_t* matrix_a = matrix_create(3, 3, (double*) values_a);
	double values_b[][3] = {{1.0, 3.0, 5.0},
							{4.0, 4.0, 7.0},
							{1.0, 1.0, 0.0}};
	matrix_t* matrix_b = matrix_create(3, 3, (double*) values_b);

	// Act
	int actual_result = matrix_cmp(matrix_a, matrix_b);

	// Assert
	ASSERT_EQ(actual_result, 1);
}

TEST(matrix, matrix_transponse) {
	// Arrange
	matrix_t* matrix = matrix_identity(3);

	// Act
	matrix = matrix_transpose(matrix);

	// Assert
	ASSERT_EQ(matrix->values[2][2], 1);
	ASSERT_EQ(matrix->values[1][1], 1);
	ASSERT_EQ(matrix->values[0][0], 1);
}
