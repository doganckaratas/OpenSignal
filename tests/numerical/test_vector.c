/* OpenSignal
 * test_vector.c | Numerical library test functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "numerical/vector.h"

#include "test_numerical.h"

int test_vector()
{
#ifdef VECTOR_BASIC_TEST
	Vector_t *v = vector_new();
	Vector_t *w = vector_new();
	printf("\nVector v init\n");
	printf("Vector w init\n");
	vector_size(v, 3, SHAPE_HORIZ);
	vector_size(w, 3, SHAPE_HORIZ);
	printf("v = Vector(3,SHAPE_HORIZ)\n");
	printf("w = Vector(3,SHAPE_HORIZ)\n");
	printf("\nvector_ones(v) : \n");
	vector_ones(v);
	vector_print(v);
	printf("\nvector_zeros(v) : \n");
	vector_zeros(v);
	vector_print(v);
	printf("\nvector_set_all(v, -25) : \n");
	vector_set_all(v, -25);
	vector_print(v);
	printf("\nvector_set_all(v, 10) : \n");
	vector_set_all(w, 10);
	vector_print(w);
	printf("\nvector_add(v, w) : \n");
	vector_add(v, w);
	vector_print(v);
	vector_delete(v);
	vector_delete(w);
	printf("\nVector v delete");
	printf("\nVector w delete\n");
#endif
	return 0;
}
