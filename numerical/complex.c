/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "complex.h"

Complex_t* complex(void)
{
	return (Complex_t *) malloc(sizeof(Complex_t));
}

int complex_init(Complex_t *c, double i, double j)
{
	if (c == NULL) {
		return -1;
	}
	c->real = i;
	c->imag = j;
	return 0;
}

double complex_get_real(Complex_t *c)
{
	if (c == NULL) {
		return 0;
	}
	return c->real;
}

double complex_get_imag(Complex_t *c)
{
	if (c == NULL) {
		return 0;
	}
	return c->imag;
}

int complex_set_real(Complex_t *c, double i)
{
	if (c == NULL) {
		return -1;
	}
	c->real = i;
	return 0;
}

int complex_set_imag(Complex_t *c, double j)
{
	if (c == NULL) {
		return -1;
	}
	c->imag = j;
	return 0;
}

/** @fn complex_compare(c1, c2)
    @brief compares two complex numbers
    @param[in] c1 first number to be compared
    @param[in] c2 second number to be compared
    @returns 0 if c1 == c2
    @returns 1 if c1 != c2
    @returns -1 if error
*/
int complex_compare(Complex_t *c1, Complex_t *c2)
{
	if (c1 == NULL || c2 == NULL) {
		return -1;
	}

	if (complex_get_real(c1) == complex_get_real(c2) &&
		complex_get_imag(c1) == complex_get_imag(c2)) {
		return 0;
	} else {
		return 1;
	}
}

int complex_to_polar(Complex_t *c, Polar_t *p)
{
	if (c == NULL || p == NULL) {
		return -1;
	}
	
	p->radius = sqrt(pow(complex_get_real(c), 2) + pow(complex_get_imag(c), 2));
	p->angle = atan2(complex_get_imag(c), complex_get_real(c));
	
	return 0;
}

int complex_print(Complex_t *c)
{
	if (c == NULL) {
		return -1;
	}

	printf("%lf + %lfi", complex_get_real(c), complex_get_imag(c));
	return 0;
}

int complex_delete(Complex_t *c)
{
	if (c == NULL) {
		return -1;
	}

	free(c);
	c = NULL;
	return 0;
}
