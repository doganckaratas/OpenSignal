/* OpenSignal
 * test_vector.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "vector.h"

#include "test_numerical.h"

int test_vector()
{
	printf("Vector v init\n");
	Vector_t *v = vector_new();
	printf("Vector v delete\n");
	vector_delete(v);

	return 0;
}
