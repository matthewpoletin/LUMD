#include <stdio.h>
#include <time.h>

#include "matrix.h"
#include "lu/single.h"

void single_preset_test() {
	printf("Тест для предопределённых значений\n");
	// Создание матрицы с заданными значениями
	double values[][3] = {{1.0, 3.0, 5.0},
						  {2.0, 4.0, 7.0},
						  {1.0, 1.0, 0.0}};
	matrix_t* matrix = matrix_create(3, 3, values);
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
}

void single_random_test() {
	printf("Тест для случайных значений\n");
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
}

int main(int argc, char** argv) {
	// Инициализация рандомайзера
	srand((unsigned int) time(NULL));
	// Тест для предопределённых значений
	single_preset_test();
	printf("\n");
	// Тест для случайных значений
	single_random_test();

	return 0;
}