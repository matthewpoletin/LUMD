#ifndef LUDM_MATRIX_H
#define LUDM_MATRIX_H

/**
 * Данные матрицы
 */
typedef struct {
	// Размер матрицы
	int m, n;
	// Значения матрицы
	double** values;
} matrix_t;

/**
 * Результат LU разложения матрицы
 */
typedef struct {
	// Матрица L
	matrix_t L;
	// Матрица U
	matrix_t U;
} LU_t;

/**
 * Создание новой матрицы
 * @param m Размер матрицы m
 * @param n Размер матрицы n
 * @return Созданная нулевая матрица
 */
matrix_t matrix_new(int m, int n);

/**
 * Создание новой матрицы на основе параметров
 * @param values Значения
 * @param m Размер m
 * @param n Размер n
 * @return Созданная матрица
 */
matrix_t* matrix_create(double** values, int m, int n);

/**
 * Копирование существующей матрицы
 * @param matrix Существующая матрица
 * @return Новая матрица на основе уже имеющейся
 */
matrix_t matrix_copy(matrix_t* matrix);

/**
 * Удаление матрицы
 * @param matrix
 */
void matrix_delete(matrix_t* matrix);

/**
 * Вывод матрицы с заданным форматом
 * @param matrix Матрица
 * @param fmt Формат
 */
void matrix_show(matrix_t* matrix, const char* fmt);

/**
 * Перемножение матриц
 * @param matrix_a Матрица A
 * @param matrix_b Матрица B
 * @return Результат перемножения двух матриц
 */
matrix_t matrix_multiply(matrix_t* matrix_a, matrix_t* matrix_b);

/**
 * LU разложение матрицы
 * @param A Матрица A для разложения
 * @param R Матрица R ???
 * @return Резултат LU разложения
 */
LU_t matrix_LU_decomposition(matrix_t* A, matrix_t* R);

#endif //LUDM_MATRIX_H
