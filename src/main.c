#include <stdio.h>
#include <time.h>

#include "matrix.h"
#include "lu/single.h"
#include "lu/mpi.h"

void single_preset_test() {
	printf("Однопоточный тест для предопределённых значений\n");
	// Создание матрицы с заданными значениями
	double values[][3] = {{1.0, 3.0, 5.0},
						  {2.0, 4.0, 7.0},
						  {1.0, 1.0, 0.0}};
	matrix_t* matrix = matrix_create(3, 3, (double*) values);
	// Вывод матрицы на экран
	matrix_show(matrix, "A", 0);
	// Однопоточное LU разложение матрицы
	LU_t result = single_LU(matrix);
	// Вывод матрицы на экран
	matrix_show(result.L, "L", 0);
	matrix_show(result.U, "U", 0);
	matrix_show(matrix_multiply(result.L, result.U), "R", 0);
	// Очистка значений
	matrix_delete(matrix);
	matrix_delete(result.L);
	matrix_delete(result.U);
	printf("\n");
}

void single_random_test() {
	printf("Однопоточный тест для случайных значений\n");
	// Создание матрицы случайных значений
	matrix_t* matrix = matrix_random(5, 5, 0.0, 10.0);
	// Вывод матрицы на экран
	matrix_show(matrix, "A", 0);
	// Однопоточное LU разложение матрицы
	LU_t result = single_LU(matrix);
	// Вывод матрицы на экран
	matrix_show(result.L, "L", 0);
	matrix_show(result.U, "U", 0);
	// Очистка значений
	matrix_delete(matrix);
	matrix_delete(result.L);
	matrix_delete(result.U);
	printf("\n");
}

void mpi_preset_test() {
	printf("MPI Тест для предопределённых значений\n");
	// Создание матрицы с заданными значениями
	double values[][3] = {{1.0, 3.0, 5.0},
						  {2.0, 4.0, 7.0},
						  {1.0, 1.0, 0.0}};
	matrix_t* matrix = matrix_create(3, 3, (double*) values);
	// Вывод матрицы на экран
	matrix_show(matrix, "A", 0);
	// MPI LU разложение матрицы
	LU_t result = mpi_LU(matrix);
	// Вывод матрицы на экран
	matrix_show(result.L, "L", 0);
	matrix_show(result.U, "U", 0);
	matrix_show(matrix_multiply(result.L, result.U), "R", 0);
	// Очистка значений
	matrix_delete(matrix);
	matrix_delete(result.L);
	matrix_delete(result.U);
	printf("\n");
}

int main(int argc, char** argv) {
	// Инициализация рандомайзера
	srand((unsigned int) time(NULL));
	// Однопоточный тест для предопределённых значений
	single_preset_test();
	// Однопоточный тест для случайных значений
	single_random_test();
	// MPI тест для предопределённых значений
	mpi_preset_test();

	return 0;
}