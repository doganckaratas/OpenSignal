/* OpenSignal
 * test.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "numerical/polar.h"
#include "numerical/complex.h"
#include "numerical/matrix.h"
#include "numerical/vector.h"

#include "test_numerical.h"

int main()
{
#ifdef COMPLEX_TEST
	test_complex();
#endif /* COMPLEX_TEST */

#ifdef POLAR_TEST
	test_polar();
#endif /* POLAR_TEST */

#ifdef MATRIX_TEST
	test_matrix();
#endif /* MATRIX_TEST */

#ifdef VECTOR_TEST
	test_vector();
#endif /* VECTOR_TEST */

	return 0;
}
