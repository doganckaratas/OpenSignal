/* OpenSignal
 * vector.c | Vector functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numerical/vector.h"

Vector_t * vector_new(void)
{
        return (Vector_t *) malloc(sizeof(Vector_t));
}

int	vector_size(Vector_t *v, int size, enum vector_shape shape)
{
	if (v == NULL || size < 0) {
		return -1;
	}

	v->size = size;
	v->shape = shape;
        v->data = (double *) malloc(sizeof(double) * size);

        if (v->data == NULL) {
                return -1;
        }
        vector_zeros(v);
	return 0;
}

int 	vector_get_elem(Vector_t *v, int idx, double *elem)
{
        /* exceeds 80 line */
        if (v == NULL || v->data == NULL || elem == NULL || v->size < 0 || idx < 0) {
                return -1;
        }

        *elem = *(v->data + idx - 1);
        return 0;
}

int	vector_set_elem(Vector_t *v, int idx, double elem)
{
        if (v == NULL || v->data == NULL || v->size < 0 || idx < 0) {
                return -1;
        }

        *(v->data + idx - 1) = elem;
        return 0;
}

int	vector_get_shape(Vector_t *v, enum vector_shape *shape)
{
        if (v == NULL || v->data == NULL || shape == NULL) {
                return -1;
        }

        *shape = v->shape;
        return 0;
}

int	vector_set_shape(Vector_t *v, enum vector_shape shape)
{
        if (v == NULL || v->data == NULL) {
                return -1;
        }

        v->shape = shape;
        return 0;
}

int     vector_set_all(Vector_t *v, double elem)
{
        if (v == NULL || v->data == NULL || v->size < 0) {
                return -1;
        }

        for (int i = 0; i < v->size; i++) {
                vector_set_elem(v, i + 1, elem);
        }
        return 0;
}

int	vector_zeros(Vector_t *v)
{
        if (v == NULL || v->data == NULL || v->size < 0) {
                return -1;
        }

        vector_set_all(v, 0);
        return 0;
}

int     vector_ones(Vector_t *v)
{
        if (v == NULL || v->data == NULL || v->size < 0) {
                return -1;
        }

        vector_set_all(v, 1);
        return 0;
}
#if 0
int	vector_from_scalar(Vector_t *v, double *scalar, enum vector_shape shape)
{

}

int	vector_to_scalar(Vector_t *v, double *scalar, enum vector_shape shape)
{

}
#endif
int	vector_add(Vector_t *v1, Vector_t *v2)
{
	enum vector_shape shape1 = 0, shape2 = 0;
	int i = 0;
	double data1 = 0, data2 = 0;
	if (v1 == NULL || v2 == NULL) {
		return -1;
	}

	if (v1->data == NULL || v2->data == NULL) {
		return -2;
	}

	vector_get_shape(v1, &shape1);
	vector_get_shape(v2, &shape2);
	if (shape1 != shape2) {
		return -3;
	}

	if (v1->size != v2->size) {
		return -4;
	}

	for (i = 1; i <= v1->size; i++) {
		vector_get_elem(v1, i, &data1);
		vector_get_elem(v2, i, &data2);
		vector_set_elem(v1, i, data1 + data2);
	}

	return 0;
}

int	vector_subtract(Vector_t *v1, Vector_t *v2)
{
	enum vector_shape shape1 = 0, shape2 = 0;
	int i = 0;
	double data1 = 0, data2 = 0;
	if (v1 == NULL || v2 == NULL) {
		return -1;
	}

	if (v1->data == NULL || v2->data == NULL) {
		return -2;
	}

	vector_get_shape(v1, &shape1);
	vector_get_shape(v2, &shape2);
	if (shape1 != shape2) {
		return -3;
	}

	if (v1->size != v2->size) {
		return -4;
	}

	for (i = 1; i <= v1->size; i++) {
		vector_get_elem(v1, i, &data1);
		vector_get_elem(v2, i, &data2);
		vector_set_elem(v1, i, data1 - data2);
	}

	return 0;
}
#if 0
int	vector_multiply(Vector_t *v1, Vector_t *v2)
{

}

int     vector_to_matrix(Vector_t **v, Matrix_t *m)
{
        /* This function relies to vector arrays */
        /* refer to matrix array */
}

int     vector_copy(Vector_t *v1, Vector_t *v2)
{

}
#endif
int     vector_print(Vector_t *v)
{
	int i = 0;
	double data = 0;
	if (v == NULL || v->data == NULL) {
		return -1;
	}

	printf("<");
	for (i = 1; i <= v->size; i++) {
		vector_get_elem(v, i, &data);
		printf("%.3lf ", data);
	}
	printf(">\n");
	return 0;
}

int     vector_delete(Vector_t *v)
{
        if (v == NULL || v->data == NULL) {
                return -1;
        }

        free(v->data);
        v->data = NULL;
        free(v);
        v = NULL;
        return 0;
}
