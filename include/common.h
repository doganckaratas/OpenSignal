#ifndef __COMMON_H
#define __COMMON_H

typedef struct Polar {
	double radius;
	double angle;
} Polar_t;

typedef struct Complex {
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

#endif /* __COMMON_H */
