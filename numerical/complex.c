/* OpenSignal
 * complex.c | Complex number functions
 * Dogan C. Karatas | 2018 | GNU GPL v3 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical/complex.h"

Complex_t* complex_new(void)
{
	return (Complex_t *) malloc(sizeof(Complex_t));
}

int complex_set(Complex_t *c, double i, double j)
{
	if (c == NULL) {
		return -1;
	}
	c->real = i;
	c->imag = j;
	return 0;
}

int complex_get_real(Complex_t *c, double *i)
{
	if (c == NULL) {
		return -1;
	}

	*i = c->real;
	return 0;
}

int complex_get_imag(Complex_t *c, double *j)
{
	if (c == NULL) {
		return -1;
	}

	*j = c->imag;
	return 0;
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
	double c1_i = 0.0, c1_j = 0.0;
	double c2_i = 0.0, c2_j = 0.0;

	if (c1 == NULL || c2 == NULL) {
		return -1;
	}

	if (complex_get_real(c1, &c1_i) < 0) {
		return -1;
	}

	if (complex_get_imag(c1, &c1_j) < 0) {
		return -1;
	}

	if (complex_get_real(c2, &c2_i) < 0) {
		return -1;
	}

	if (complex_get_imag(c2, &c2_j) < 0) {
		return -1;
	}

	if (c1_i == c2_i && c1_j == c2_j) {
		return 0;
	} else {
		return 1;
	}
}

int complex_to_polar(Complex_t *c, Polar_t *p)
{
	double i = 0.0, j = 0.0;

	if (c == NULL || p == NULL) {
		return -1;
	}

	if (complex_get_real(c, &i) < 0) {
		return -1;
	}

	if (complex_get_imag(c, &j) < 0) {
		return -1;
	}

	p->radius = sqrt(pow(i, 2) + pow(j, 2));
	p->angle = atan2(j, i);

	return 0;
}

int complex_print(Complex_t *c)
{
	double i = 0.0, j = 0.0;

	if (c == NULL) {
		return -1;
	}

	if (complex_get_real(c, &i) < 0) {
		return -1;
	}

	if (complex_get_imag(c, &j) < 0) {
		return -1;
	}

	printf("%lf + %lfi", i, j);
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
