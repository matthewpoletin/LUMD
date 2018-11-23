#include <stdio.h>
#include <time.h>

#include "matrix.h"

int main(int argc, char** argv) {
	// Инициализация рандомайзера
	srand((unsigned int) time(NULL));
	// Создание матрицы случайных значений
	matrix_t* matrix = matrix_random(5, 4, 0.0, 10.0);
	// Вывод матрицы на экран
	matrix_show(matrix, 0);

	return 0;
}