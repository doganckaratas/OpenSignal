/* OpenSignal
 * vector.c | Vector functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "vector.h"

Vector_t * vector_new(void)
{
        return (Vector_t *) malloc(sizeof(Vector_t));
}
#if 0
int	vector_size(Vector_t *v, int num, int orientation)
{

}

int 	vector_get_elem(Vector_t *v, int num)
{

}

int	vector_set_elem(Vector_t *v, int num)
{

}

int	vector_from_scalar(Vector_t *v, double *scalar, int orientation)
{

}

int	vector_to_scalar(Vector_t *v, double *scalar, int orientation)
{

}

int	vector_set_orientation(Vector_t *v, int orientation)
{

}

int	vector_add(Vector_t *v1, Vector_t *v2)
{

}

int	vector_subtract(Vector_t *v1, Vector_t *v2)
{

}

int	vector_multiply(Vector_t *v1, Vector_t *v2)
{

}
#endif
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
