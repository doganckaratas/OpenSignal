/* OpenSignal
 * test_matrix.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "numerical/matrix.h"

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

#ifdef MATRIX_ARRAY_TEST
	/* Group these declarations as functions */
	Matrix_t *marr[3] = { matrix_new(), matrix_new(), matrix_new() };
	printf("\nCreated Matrix Array marr[3]\n");
	matrix_size(marr[0], 3, 3);
	matrix_size(marr[1], 3, 3);
	matrix_size(marr[2], 3, 3);

	matrix_zeros(marr[0]);
	matrix_ones(marr[1]);
	matrix_identity(marr[2]);

	printf("marr[0] is zeros()\n");
	matrix_print(marr[0]);
	printf("\nmarr[1] is ones()\n");
	matrix_print(marr[1]);
	printf("\nmarr[2] is identity\n");
	matrix_print(marr[2]);

	matrix_delete(marr[0]);
	matrix_delete(marr[1]);
	matrix_delete(marr[2]);
#endif /* MATRIX_ARRAY_TEST */

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
	matrix_identity(m_eye);
	printf("\nIdentity Matrix I[3x3] =\n");
#endif /* MATRIX_IDENTITY_TEST */

#ifdef MATRIX_COPY_TEST
	Matrix_t *m_orig = matrix_new();
	Matrix_t *m_copy = matrix_new();
	matrix_size(m_orig, 3, 3);
	matrix_set_cell(m_orig, 1, 1, 2);
	matrix_set_cell(m_orig, 2, 2, -2);
	matrix_set_cell(m_orig, 3, 3, 2);
	printf("\nMatrix m_orig [3x3] =\n");
	matrix_print(m_orig);
	printf("\nCopied m_copy[3x3] :\n");
	matrix_copy(m_orig, m_copy);
	matrix_print(m_copy);
	matrix_delete(m_copy);
	matrix_delete(m_orig);
#endif /* MATRIX_COPY_TEST */

#ifdef MATRIX_TRANSPOSE_TEST
	Matrix_t *m_trans = matrix_new();
	printf("\nNormal 2x3:\n");
	matrix_size(m_trans, 2, 3);
	matrix_set_cell(m_trans, 1, 1, 1);
	matrix_set_cell(m_trans, 1, 2, 2);
	matrix_set_cell(m_trans, 1, 3, 3);
	matrix_set_cell(m_trans, 2, 1, 4);
	matrix_set_cell(m_trans, 2, 2, 5);
	matrix_set_cell(m_trans, 2, 3, 6);

	matrix_print(m_trans);
	printf("\nTransposed 2x3:\n");
	matrix_transpose(m_trans);
	matrix_print(m_trans);
	matrix_transpose(m_trans);
	printf("\nRetransposed:\n");
	matrix_print(m_trans);
	matrix_delete(m_trans);
#endif /* MATRIX_TRANSPOSE_TEST */

	return 0;
}
