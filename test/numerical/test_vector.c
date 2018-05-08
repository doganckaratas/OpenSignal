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
#ifdef VECTOR_BASIC_TEST
	Vector_t *v = vector_new();
	printf("\nVector v init\n");
	vector_size(v, 3, SHAPE_HORIZ);
	printf("\nv = Vector(3,SHAPE_HORIZ) , v->size = %d v->shape = %d\n",
		v->size, v->shape);
	vector_delete(v);
	printf("\nVector v delete\n");
#endif
	return 0;
}
