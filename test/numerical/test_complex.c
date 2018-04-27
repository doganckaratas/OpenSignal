/* OpenSignal
 * test_complex.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "complex.h"
#include "polar.h"

#include "test_numerical.h"

int test_complex()
{
	Complex_t *c = complex_new();
	printf("Uninitialized Complex_t *c = \n");
	complex_print(c);
	printf("\n");

	complex_set(c, 3, 44);
	printf("\nInitialized Complex_t *c = \n");
	complex_print(c);
	printf("\n");

	complex_set_imag(c, 90);
	printf("\nImaginary component set to 90 Complex_t *c = \n");
	complex_print(c);
	printf("\n");

	Complex_t *c_new = complex_new();
	complex_set(c_new, 0, 0);

	printf("\nComparing c(3,90) == c_new(0,0) -> %d\n\n", complex_compare(c, c_new));
	complex_delete(c);

	Polar_t *p_new = polar_new();
	polar_set(p_new, 0, 0);
	complex_set_real(c_new, sqrt(2)/2);
	complex_set_imag(c_new, sqrt(2)/2);
	complex_to_polar(c_new, p_new);

	printf("\nComplex %lf + %lfi = Polar %lf|%lf * PI (rad)\n",c_new->real, c_new->imag, p_new->radius, p_new->angle/M_PI);
	polar_delete(p_new);
	complex_delete(c_new);
	return 0;
}
