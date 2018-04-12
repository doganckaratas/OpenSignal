#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "common.h"
#include "polar.h"
#include "complex.h"
#include "matrix.h"

int main()
{
#ifdef COMPLEX_TEST
	Complex_t *c = complex();
	printf("Uninitialized Complex_t *c = \n");
	complex_print(c);
	printf("\n");

	complex_init(c, 3, 44);
	printf("\nInitialized Complex_t *c = \n");
	complex_print(c);
	printf("\n");

	complex_set_imag(c, 90);
	printf("\nImaginary component set to 90 Complex_t *c = \n");
	complex_print(c);
	printf("\n");

	Complex_t *c_new = complex();
	complex_init(c_new, 0, 0);

	printf("\nComparing c(3,90) == c_new(0,0) -> %d\n\n", complex_compare(c, c_new));
	complex_delete(c);
#endif /* COMPLEX_TEST */

#ifdef POLAR_TEST
	Polar_t *p = polar();
	polar_init(p, 2, 4);
	printf("Initialized Polar_t *p = \n");
	polar_print(p);
	printf("\n");
	polar_delete(p);
#endif /* POLAR_TEST */

#if defined(COMPLEX_TEST) && defined(POLAR_TEST)
	Polar_t *p_new = polar();
	polar_init(p_new, 0, 0);
	complex_set_real(c_new, sqrt(2)/2);
	complex_set_imag(c_new, sqrt(2)/2);
	complex_to_polar(c_new, p_new);

	printf("\nComplex %lf + %lfi = Polar %lf|%lf * PI (rad)\n",c_new->real, c_new->imag, p_new->radius, p_new->angle/M_PI);

	complex_init(c_new, 0, 0);
	polar_init(p_new, 5, 0.6457242582897); /* 5|37 */
	polar_to_complex(p_new, c_new);

	printf("Complex %lf + %lfi = Polar %lf|%lf * PI (rad)\n\n",c_new->real, c_new->imag, p_new->radius, p_new->angle/M_PI);
	polar_delete(p_new);
#endif /* COMPLEX_TEST && POLAR_TEST */

#ifdef MATRIX_TEST
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
	matrix_identity(m_eye);
	matrix_print(m_eye);
	matrix_delete(m_eye);
	matrix_delete(m_eye);
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

#endif /* MATRIX_TEST */
	return 0;
}
