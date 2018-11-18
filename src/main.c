#include <stdio.h>

#include "matrix.h"

int main(int argc, char** argv) {
	double** values = {{1, 3, 5},
					   {2, 4, 7},
					   {1, 1, 0}};
	matrix_t * matrix = matrix_create(values, 3, 3);
	return 0;
}
