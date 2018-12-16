#ifndef LUDM_MATRIX_H
#define LUDM_MATRIX_H

#include <stdlib.h>

/**
 * Данные матрицы
 */
typedef struct {
	// Размер матрицы
	size_t m, n;
	// Значения матрицы
	double** values;
} matrix_t;

/**
 * Заполнение матрицы нулями
 * @param matrix Матрица
 */
matrix_t* matrix_zero(matrix_t* matrix);

/**
 * Создание нулевой матрицы заданных размеров
 * @param m Размер матрицы m
 * @param n Размер матрицы n
 * @return Созданная нулевая матрица
 */
matrix_t* matrix_new(size_t m, size_t n);

/**
 * Создание новой матрицы на основе параметров
 * @param values Значения
 * @param m Размер m
 * @param n Размер n
 * @return Созданная матрица
 */
matrix_t* matrix_create(size_t m, size_t n, double* values);

/**
 * Копирование существующей матрицы
 * @param matrix Существующая матрица
 * @return Новая матрица на основе уже имеющейся
 */
matrix_t* matrix_copy(matrix_t* matrix);

/**
 * Удаление матрицы
 * @param matrix
 */
void matrix_delete(matrix_t* matrix);

/**
 * Перемножение двух матриц
 * @param a Матрица А
 * @param b Матрица B
 * @return Результат перемножения
 */
matrix_t* matrix_multiply(matrix_t* a, matrix_t* b);

/**
 * Вывод матрицы с заданным форматом
 * @param matrix Матрица
 * @param fmt Формат
 */
void matrix_show(matrix_t* matrix, const char* name, const char* fmt);

/**
 * Создание матрицы случайных значений
 * @param m Размер m
 * @param n Размер n
 * @param min Нижнее значение
 * @param max Верхнее значение
 * @return Матрица случайных значений
 */
matrix_t* matrix_random(size_t m, size_t n, double min, double max);

/**
 * Создание единичной матрицы
 * @param m Размер m
 * @param n Размер n
 * @return Единичная матрица
 */
matrix_t* matrix_identity(size_t m);

/**
 * Транспонирование матрицы
 * @param matrix Исходная матрица
 * @return Транспонированная матрица
 */
matrix_t* matrix_transpose(matrix_t* matrix);

/**
 * Численное сравнение двух матриц
 * @param a Первая матрица
 * @param b Вторая матрица
 * @return Результат сравнения
 */
int matrix_cmp(matrix_t* a, matrix_t* b);

/**
 * Установка значения матрицы
 * @param matrix Матрица
 * @param i Позиция по m
 * @param j Позиция по n
 * @param value Значение
 * @return Результат
 */
int matrix_set(matrix_t* matrix, size_t i, size_t j, double value);

/**
 * Получение значения матрицы
 * @param matrix Матрица
 * @param i Позиция по m
 * @param j Позиция по n
 * @return Результат
 */
double matrix_get(matrix_t* matrix, size_t i, size_t j);

#endif //LUDM_MATRIX_H
