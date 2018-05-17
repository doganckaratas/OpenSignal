/* OpenSignal
 * matrix.c | Matrix functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

Matrix_t* matrix_new(void)
{
	return (Matrix_t *) malloc(sizeof(Matrix_t));
}

int matrix_size(Matrix_t *m, int row, int col)
{
	if (m == NULL || row <= 0 || col <= 0) {
		return -1;
	}
	m->rows = row;
	m->cols = col;
	m->data = malloc(sizeof(double) * row * col + 1);

	if (m->data == NULL) {
		return -1;
	}
	matrix_zeros(m);
	return 0;
}
#if 0
int matrix_define(Matrix_t *m, char* data)
{
	matrix_define(m, "[1 2 3; 4 5 6; 7 8 9 ]");
}
#endif
int matrix_set_cell(Matrix_t *m, int row, int col, double data)
{
	if (m->data == NULL || m == NULL || row <= 0 || col <= 0) {
		return -1;
	}

	*(m->data + ((row - 1) * m->cols + (col - 1))) = data;
	return 0;
}

int matrix_get_cell(Matrix_t* m, int row, int col, double *data)
{
	if (m->data == NULL || m == NULL || row <= 0 || col <= 0) {
		return -1;
	}

	*data = *(m->data + ((row - 1) * m->cols + (col - 1)));
	return 0;
}
#if 0
int matrix_set_row(Matrix_t *m, int row, Vector_t *v)
{
	/* if matrix is vertical, deny it */
}

int matrix_set_col(Matrix_t *m, int col, Vector_t *v)
{
	/* if matrix is horizontal, deny it */
}

int matrix_get_row(Matrix_t *m, int row, Vector_t *v)
{

}

int matrix_get_col(Matrix_t *m, int col, Vector_t *v)
{

}
#endif
int matrix_set_all(Matrix_t *m, double data)
{
	int i = 0, j = 0;
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	for (i = 1; i <= m->rows; i++) {
		for (j = 1; j <= m->cols; j++) {
			matrix_set_cell(m, i, j, data);
		}
	}
	return 0;
}

int matrix_zeros(Matrix_t *m)
{
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	matrix_set_all(m, 0);
	return 0;
}

int matrix_ones(Matrix_t *m)
{
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	matrix_set_all(m, 1);
	return 0;
}

int matrix_identity(Matrix_t *m)
{
	int i = 0, j = 0;
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	for (i = 1; i <= m->rows; i++) {
		for (j = 1; j <= m->cols; j++) {
			if (i == j) {
				matrix_set_cell(m, i, j, 1);
			} else {
				matrix_set_cell(m, i, j, 0);
			}
		}
	}
	return 0;
}
#if 0
int matrix_product(Matrix_t *m1, Matrix_t *m2)
{

}
#endif
int matrix_copy(Matrix_t *m1, Matrix_t *m2)
{
	if (m1->data == NULL || m1 == NULL) {
		return -1;
	}

	if (m2 == NULL) {
		m2 = matrix_new();
	}

	matrix_size(m2, m1->rows, m1->cols);
	/* exceeds 80 line */
	memcpy(m2->data, m1->data, sizeof(double) * (size_t)(m1->rows * m1->cols));

	if (m2->data == NULL) {
		return -1;
	}

	return 0;
}
#if 0
int matrix_inverse(Matrix_t *m)
{

}

int matrix_determinant(Matrix_t *m, double *result)
{

}

int matrix_echelon(Matrix_t *m)
{
	// for easier determinant operation
	// needs vector operations
}
#endif
int matrix_transpose(Matrix_t *m)
{
	int i = 0, j = 0;
	double tmp = 0;
	Matrix_t *m_tmp = matrix_new();
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	matrix_size(m_tmp, m->cols, m->rows);

	for (i = 1; i <= m->rows; i++) {
		for(j = 1; j <= m->cols; j++) {
			matrix_get_cell(m, i, j, &tmp);
			matrix_set_cell(m_tmp, j, i, tmp);
		}
	}
	matrix_copy(m_tmp, m);
	matrix_delete(m_tmp);
	return 0;
}
#if 0
int matrix_to_vector_slice(Matrix_t *m, enum vector_shape shape, int n, Vector_t *v)
{

}

int matrix_eigenvalues(Matrix_t *m, ...)
{

}

int matrix_eigenvectors(Matrix_t *m, ...)
{

}
#endif
int matrix_print(Matrix_t *m)
{
	int i = 0, j = 0;
	double data = 0;
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	for (i = 1; i <= m->rows; i++) {
		for (j = 1; j <= m->cols; j++) {
			matrix_get_cell(m, i, j, &data);
			printf("%.3lf ", data);
		}
		printf("\n");
	}
	return 0;
}

int matrix_compare(Matrix_t *m1, Matrix_t *m2)
{
	int i = 0;
	if (m1->data == NULL || m1 == NULL ||
		m2->data == NULL || m2 == NULL) {
		return -1;
	}

	if (m1->rows != m2->rows || m1->cols != m2->cols) {
		return 1;
	}

	/* cycle through array */
	for(i = 0; i < (m1->rows * m1->cols); i++) {
		if ( *(m1->data + i) != *(m2->data + i)) {
			return 1;
		}
	}
	return 0;
}

int matrix_delete(Matrix_t *m)
{
	if (m->data == NULL || m == NULL) {
		return -1;
	}

	free(m->data);
	m->data = NULL;
	free(m);
	m = NULL;
	return 0;
}
