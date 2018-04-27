/* OpenSignal
 * test_polar.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "complex.h"
#include "polar.h"

#include "test_numerical.h"

int test_polar()
{
	Polar_t *p = polar_new();
	polar_set(p, 2, 4);
	printf("Initialized Polar_t *p = \n");
	polar_print(p);
	printf("\n");
	polar_delete(p);

	Polar_t *p_new = polar_new();
	Complex_t *c_new = complex_new();

	complex_set(c_new, 0, 0);
	polar_set(p_new, 5, 0.6457242582897); /* 5|37 */
	polar_to_complex(p_new, c_new);

	printf("Complex %lf + %lfi = Polar %lf|%lf * PI (rad)\n\n",c_new->real, c_new->imag, p_new->radius, p_new->angle/M_PI);
	polar_delete(p_new);
	complex_delete(c_new);

	return 0;
}
