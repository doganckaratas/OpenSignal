/* OpenSignal
 * test_matrix.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "matrix.h"

#include "test_numerical.h"

int test_matrix()
{
#ifdef MATRIX_BASIC_TEST
	Matrix_t *m = matrix_new();
	matrix_size(m, 3, 3);

	printf("New Matrix %dx%d\n", m->rows, m->cols);
	matrix_print(m);

	matrix_ones(m);
	printf("\nones() Matrix\n");
	matrix_print(m);

	matrix_set_cell(m, 1, 2, -2);
	matrix_set_cell(m, 3, 3, 10);
	matrix_set_cell(m, 2, 3, 0.23231);
	printf("\nChanged m[1x2] = -2, m[3x3] = 10 and m[2x3] = 0.23231\n");
	matrix_print(m);

	matrix_zeros(m);
	printf("\nZeroed all cells m[ixj]\n");
	matrix_print(m);
	matrix_delete(m);
#endif /* MATRIX_BASIC_TEST */

#ifdef MATRIX_COMPARE_TEST
	Matrix_t *m_cmp = matrix_new();
	matrix_size(m_cmp, 3, 3);
	matrix_set_cell(m_cmp, 1, 1, 2);
	matrix_set_cell(m_cmp, 2, 2, 4);
	matrix_set_cell(m_cmp, 3, 3, 6);
	printf("\nMatrix m [3x3] =\n");
	matrix_print(m_cmp);

	Matrix_t *m_new = matrix_new();
	matrix_size(m_new, 3, 3);
	matrix_zeros(m_new);
	matrix_set_cell(m_new, 1, 1, 2);
	matrix_set_cell(m_new, 2, 2, 4);
	matrix_set_cell(m_new, 3, 3, 6);
	printf("\nMatrix m_new [3x3] =\n");
	matrix_print(m_new);

	printf("\nMatrix Compare m[3,3] == m_new[3,3] -> %s\n", matrix_compare(m_cmp, m_new) ? "UNEQUAL" : "EQUAL");
	matrix_delete(m_new);
	matrix_delete(m_cmp);
#endif /* MATRIX_COMPARE_TEST */

#ifdef MATRIX_IDENTITY_TEST
	Matrix_t *m_eye = matrix_new();
	matrix_size(m_eye, 3, 3);
	printf("\nIdentity Matrix I[3x3] =\n");
#endif /* MATRIX_IDENTITY_TEST */
	return 0;
}
