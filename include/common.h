#ifndef __COMMON_H
#define __COMMON_H

typedef struct Polar_s {
	double radius;
	double angle;
} Polar_t;

typedef struct Complex_s {
	double real;
	double imag;
} Complex_t;

typedef struct Matrix_s {
	int rows; /* m */
	int cols; /* n */
	double *data;
	/* union of different types, 
	   and abstraction funcs of 
	   these fields in .c file 
	 */
} Matrix_t;

typedef struct Vector_s {
	int size;
	int orientation; /* needs to be anonymous ENUM */
	double *data;
} Vector_t;

#endif /* __COMMON_H */
