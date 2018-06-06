/* OpenSignal
 * vector.h | vector.c header file
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#ifndef __VECTOR_H
#define __VECTOR_H

#include "common.h"

enum vector_shape {
	SHAPE_HORIZ = 0,
	SHAPE_VERT = 1,
        SHAPE_UNKNOWN = -1
};

Vector_t * vector_new(void);
int	vector_size(Vector_t *v, int size, enum vector_shape shape);
int 	vector_get_elem(Vector_t *v, int idx, double *elem);
int	vector_set_elem(Vector_t *v, int idx, double elem);
int	vector_get_shape(Vector_t *v, enum vector_shape *shape);
int	vector_set_shape(Vector_t *v, enum vector_shape shape);
int     vector_set_all(Vector_t *v, double elem);
int	vector_zeros(Vector_t *v);
int     vector_ones(Vector_t *v);
#if 0
int	vector_from_scalar(Vector_t *v, double *scalar, enum vector_shape shape);
int	vector_to_scalar(Vector_t *v, double *scalar, enum vector_shape shape);
int	vector_set_orientation(Vector_t *v, int orientation);
#endif
int	vector_add(Vector_t *v1, Vector_t *v2);
#if 0
int	vector_subtract(Vector_t *v1, Vector_t *v2);
int	vector_multiply(Vector_t *v1, Vector_t *v2);
#endif
int	vector_print(Vector_t *v);
int	vector_delete(Vector_t *v);

#endif /* __VECTOR_H */
