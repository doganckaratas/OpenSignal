/* OpenSignal
 * vector.h | vector.c header file
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#ifndef __VECTOR_H
#define __VECTOR_H

Vector_t * vector_new(void);
#if 0
int	vector_size(Vector_t *v, int num, int orientation);
int	vector_get_elem(Vector_t *v, int num);
int	vector_set_elem(Vector_t *v, int num);
int	vector_from_scalar(Vector_t *v, double *scalar, int orientation);
int	vector_to_scalar(Vector_t *v, double *scalar, int orientation);
int	vector_set_orientation(Vector_t *v, int orientation);
int	vector_add(Vector_t *v1, Vector_t *v2);
int	vector_subtract(Vector_t *v1, Vector_t *v2);
int	vector_multiply(Vector_t *v1, Vector_t *v2);
#endif
int	vector_delete(Vector_t *v);

#endif /* __VECTOR_H */
