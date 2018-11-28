#include <stdlib.h>
#include <printf.h>
#include <math.h>
#include <memory.h>

#include "matrix.h"

/**
 * Создание матрицы заданных размеров
 * @param m Размер m
 * @param n Размер n
 * @return Матрица случайных значений
 */
matrix_t* matrix_get(size_t m, size_t n) {
	// Проверка верности размеров
	if (m <= 0 || n <= 0)
		return NULL;
	// Создание матрицы
	matrix_t* matrix = malloc(sizeof(matrix_t*) + sizeof(double**) + sizeof(double*) * m * n);
	matrix->m = m;
	matrix->n = n;
	// Выделение памяти под массив данных
	matrix->values = (double**) calloc(m, sizeof(double*));
	for (int i = 0; i < m; i++)
		matrix->values[i] = (double*) calloc(n, sizeof(double));
	return matrix;
}

matrix_t* matrix_zero(matrix_t* matrix) {
	for (int i = 0; i < matrix->m; i++)
		for (int j = 0; j < matrix->n; j++)
			matrix->values[i][j] = 0;
	return matrix;
}

matrix_t* matrix_new(size_t m, size_t n) {
	// Создание матрицы
	matrix_t* matrix = matrix_get(m, n);
	if (matrix == NULL) return NULL;
	// Заполнение матрицы нулями
	return matrix_zero(matrix);
}

matrix_t* matrix_create(double** values, size_t m, size_t n) {
	// Создание матрицы
	matrix_t* matrix = matrix_get(m, n);
	if (matrix == NULL) return NULL;
	// Заполнение значений
	memcpy(values, matrix->values, sizeof(double[3][3]));
	return matrix;
}

void matrix_show(matrix_t* matrix, const char* fmt, const char* name) {
	// Вывести название матрицы
	printf("%s =", name);
	// Определить формат, если не задан
	if (!fmt) fmt = "%8.4g";
	// Вывести матрицу
	for (int i = 0; i < matrix->m; i++) {
		printf(i ? "      " : " [ ");
		for (int j = 0; j < matrix->n; j++) {
			printf(fmt, matrix->values[i][j]);
			printf(j < matrix->n - 1 ? "  " : i == matrix->n ? " ]\n" : "\n");
		}
	}
}

matrix_t* matrix_multiply(matrix_t* a, matrix_t* b) {
	// Создание нулевой выходной матрицы
	matrix_t* c = matrix_new(a->m, b->n);
	// Подсчёт значения матрицы
	for (int i = 0; i < a->n; i++)
		for (int j = 0; j < a->n; j++)
			for (int k = 0; k < a->n; k++)
				c->values[i][j] += a->values[i][k] * b->values[k][j];
	// Возвращение результата
	return c;
}

void matrix_delete(matrix_t* matrix) {
	// Очистка строк матрицы
	for (int i = 0; i < matrix->m; i++)
		free(matrix->values[i]);
	// Очистка матрицы
	free(matrix);
}

matrix_t* matrix_random(size_t m, size_t n, double min, double max) {
	// Создание матрицы
	matrix_t* matrix = matrix_get(m, n);
	if (!matrix) return NULL;
	// Заполнение значениями
	for (int i = 0; i < matrix->m; i++)
		for (int j = 0; j < matrix->m; j++)
			matrix->values[i][j] = min + ((max - min) * rand() / RAND_MAX);
	return matrix;
}
