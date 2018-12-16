#include <stdlib.h>
#include <printf.h>
#include <math.h>
#include <memory.h>
#include <matrix.h>
#include <stdbool.h>


#include "matrix.h"

/**
 * Создание матрицы заданных размеров
 * @param m Размер m
 * @param n Размер n
 * @return Матрица случайных значений
 */
matrix_t* matrix_get(size_t m, size_t n) {
	// Создание матрицы
	matrix_t* matrix = malloc(sizeof(matrix_t));
	matrix->m = m;
	matrix->n = n;
	// Выделение памяти под массив данных
	matrix->values = (double**) malloc(sizeof(double*) * m);
	for (size_t i = 0; i < m; i++)
		matrix->values[i] = (double*) malloc(sizeof(double) * n);
	return matrix;
}

matrix_t* matrix_zero(matrix_t* matrix) {
	for (size_t i = 0; i < matrix->m; i++)
		for (size_t j = 0; j < matrix->n; j++)
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

matrix_t* matrix_create(size_t m, size_t n, double* values) {
	// Создание матрицы
	matrix_t* matrix = matrix_get(m, n);
	if (matrix == NULL) return NULL;
	// Заполнение значений
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
			matrix->values[i][j] = values[i * m + j];
	return matrix;
}

void matrix_show(matrix_t* matrix, const char* name, const char* fmt) {
	// Вывести название матрицы
	printf("%s =", name);
	// Определить формат, если не задан
	if (!fmt) fmt = "%8.4g";
	// Вывести матрицу
	for (size_t i = 0; i < matrix->m; i++) {
		printf(i ? "      " : " [ ");
		for (size_t j = 0; j < matrix->n; j++) {
			printf(fmt, matrix->values[i][j]);
			printf(j < matrix->n - 1 ? "  " : i == matrix->n - 1 ? " ]\n" : "\n");
		}
	}
}

void matrix_delete(matrix_t* matrix) {
	// Очистка строк матрицы
	for (size_t i = 0; i < matrix->m; i++)
		free(matrix->values[i]);
	// Очистка матрицы
	free(matrix);
}

matrix_t* matrix_multiply_column(matrix_t* a, matrix_t* b) {
	// Проверка соответствия размеров
	if (a->n != b->m)
		return NULL;
	// Создание нулевой выходной матрицы
	matrix_t* c = matrix_new(a->m, b->n);
	if (!c)
		return NULL;
	// Создание промежуточной колоники
	double* column = (double*) malloc(sizeof(double) * b->m);
	for (size_t j = 0; j < a->n; ++j) {
		for (size_t k = 0; k < b->n; ++k)
			column[k] = b->values[j][k];
		for (size_t i = 0; i < a->m; ++i)
			for (size_t k = 0; k < a->n; ++k)
				c->values[i][j] += a->values[i][k] * column[k];
	}
	// Очистка промежуточного значения
	free(column);
	return c;
}

matrix_t* matrix_multiply_transposed(matrix_t* a, matrix_t* b) {
	// Проверка соответствия размеров
	if (a->n != b->m)
		return NULL;
	// Создание нулевой выходной матрицы
	matrix_t* c = matrix_new(a->m, b->n);
	if (!c)
		return NULL;
	// Создание промежуточной матрицы
	matrix_t* bt = matrix_transpose(b);
	for (size_t i = 0; i < a->m; ++i)
		for (size_t j = 0; j < b->n; ++j)
			for (size_t k = 0; k < a->n; ++k)
				c->values[i][j] += a->values[i][k] * bt->values[j][k];
	// Очистка промежуточного значения
	matrix_delete(bt);
	return c;
}

matrix_t* matrix_multiply_basic(matrix_t* a, matrix_t* b) {
// Проверка соответствия размеров
	if (a->n != b->m)
		return NULL;
	// Создание нулевой выходной матрицы
	matrix_t* c = matrix_new(a->m, b->n);
	if (!c)
		return NULL;
	// Подсчёт значения матрицы
	for (int i = 0; i < a->n; i++)
		for (int j = 0; j < a->n; j++)
			for (int k = 0; k < a->n; k++)
				c->values[i][j] += a->values[i][k] * b->values[k][j];
	return c;
}

matrix_t* matrix_multiply(matrix_t* a, matrix_t* b) {
	return matrix_multiply_basic(a, b);
}

matrix_t* matrix_random(size_t m, size_t n, double min, double max) {
	// Создание матрицы
	matrix_t* matrix = matrix_get(m, n);
	if (!matrix) return NULL;
	// Заполнение значениями
	for (size_t i = 0; i < matrix->m; i++)
		for (size_t j = 0; j < matrix->n; j++)
			matrix->values[i][j] = min + ((max - min) * rand() / RAND_MAX);
	return matrix;
}

matrix_t* matrix_identity(size_t m) {
	// Создание матрицы квадратной матрицы
	matrix_t* matrix = matrix_get(m, m);
	if (!matrix) return NULL;
	// Заполнение значениями
	for (size_t i = 0; i < m; i++)
		matrix->values[i][i] = 1.0;
	return matrix;
}

matrix_t* matrix_transpose(matrix_t* matrix) {
	// Создание выходной матрицы
	matrix_t* transposed = matrix_get(matrix->n, matrix->m);
	if (!transposed)
		return NULL;
	// Заполнение значениями
	for (size_t i = 0; i < matrix->m; ++i)
		for (size_t j = 0; j < matrix->n; ++j)
			transposed->values[j][i] = matrix->values[i][j];
	return transposed;
}

int matrix_compare_memory(matrix_t* a, matrix_t* b) {
	// Проверка соответсвия размеров матриц
	if (a->m != b->m || a->n != b->n)
		return -1;
	// Сравнение строк матрицы
	int res = 0;
	for (int i = 0; i < a->m; i++)
		res += abs(memcmp(a->values[i], b->values[i], sizeof(a->values[i]) * a->n));
	if (res == 0) return 0;
	else return 1;
}

int matrix_compare_values(matrix_t* a, matrix_t* b) {
	// Проверка соответсвия размеров матриц
	if (a->m != b->m || a->n != b->n)
		return -1;
	// Сравнение каждого значения
	for (int i = 0; i < a->m; i++)
		for (int j = 0; j < a->n; j++)
			if (a->values[i][j] != b->values[i][j])
				return 1;
	return 0;
}

int matrix_cmp(matrix_t* a, matrix_t* b) {
	return matrix_compare_values(a, b);
}
