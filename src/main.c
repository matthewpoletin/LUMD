#include <stdio.h>
#include <time.h>
#include <omp.h>

#include "matrix.h"
#include "lu/single.h"
#include "lu/openmp.h"

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
	matrix_t* matrix = matrix_random(10, 10, 0.0, 10.0);
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

void omp_preset_test() {
	printf("OpenMP тест для предопределённых значений\n");
	// Создание матрицы с заданными значениями
	double values[][3] = {{1.0, 3.0, 5.0},
						  {2.0, 4.0, 7.0},
						  {1.0, 1.0, 0.0}};
	matrix_t* matrix = matrix_create(3, 3, (double*) values);
	// Вывод матрицы на экран
	matrix_show(matrix, "A", 0);
	// MPI LU разложение матрицы
	LU_t result = omp_LU(matrix);
	// Вывод матрицы на экран
	matrix_show(result.L, "L", 0);
	matrix_show(result.U, "U", 0);
	matrix_show(matrix_multiply(result.L, result.U), "R", 0);
	// Очистка значений
	matrix_delete(matrix);
	matrix_delete(result.L);
	matrix_delete(result.U);
}

void omp_random_test() {
	printf("OpenMP тест для случайных значений\n");
	// Создание матрицы со случайными значениями
	matrix_t* matrix = matrix_random(10, 10, 0, 10);
	// Вывод матрицы на экран
	matrix_show(matrix, "A", 0);
	// MPI LU разложение матрицы
	LU_t result = omp_LU(matrix);
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

void compute( void (*func)()) {
	// Старт подсчёта
	double start = omp_get_wtime();
	// Выполнение функции
	func();
	// Подсчёт времени
	double end = omp_get_wtime();
	printf("Время выполнения: %lg\n\n", end - start);
}

int main(int argc, char** argv) {
	// Инициализация рандомайзера
	srand((unsigned int) time(NULL));
	// Определение числа потоков OpenMP
	omp_set_num_threads(8);
	// Однопоточный тест для предопределённых значений
	compute(single_preset_test);
	// Однопоточный тест для случайных значений
	compute(single_random_test);
	// OpenMP тест для предопределённых значений
	compute(omp_preset_test);
	// OpenMP тест для для случайных значений
	compute(omp_random_test);

	return 0;
}