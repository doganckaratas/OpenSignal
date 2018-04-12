#ifndef __MATRIX_H
#define __MATRIX_H

Matrix_t* matrix(void); 
int 	matrix_init(Matrix_t *m, int rows, int cols);
int 	matrix_set_cell(Matrix_t *m, int rows, int cols, double data);
int	matrix_get_cell(Matrix_t *m, int rows, int cols, double *data);
int 	matrix_zeros(Matrix_t *m);
int 	matrix_ones(Matrix_t *m);
int	matrix_print(Matrix_t *m);
int 	matrix_identity(Matrix_t *m);
int	matrix_product(Matrix_t *m1, Matrix_t *m2);
int	matrix_copy(Matrix_t *m1, Matrix_t *m2);
int 	matrix_inverse(Matrix_t *m);
int	matrix_determinant(Matrix_t *m, double *result);
int 	matrix_transpose(Matrix_t *m);
int 	matrix_compare(Matrix_t *m1, Matrix_t *m2);
int 	matrix_delete(Matrix_t *m);

#endif /* __MATRIX_H */
