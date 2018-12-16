#ifndef LUMD_COMMON_H
#define LUMD_COMMON_H

#include "matrix.h"

/**
 * Получить двумерный элемент из одномерного массива
 * @param M Массив
 * @param n Размер массива
 * @param i Позиция по m
 * @param j Позиция по n
 * @return Значение
 */
double array_get(double* M, int n, int i, int j);

/**
 * Установка двумерного элемента в одномерном массиве
 * @param M Массив
 * @param n Размер массива
 * @param i Размер по m
 * @param j Размер по n
 * @param val Значение
 */
void array_set(double* M, int n, int i, int j, double val);

/**
 * Преобразование матрицы к одномерному массиву
 * @param matrix Матрица
 * @return Одномерный массив
 */
double* matrix_to_array(matrix_t* matrix);

#endif //LUMD_COMMON_H
