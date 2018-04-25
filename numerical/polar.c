/* OpenSignal
 * polar.c | Polar number functions
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "polar.h"

Polar_t* polar_new(void)
{
	return (Polar_t *) malloc(sizeof(Polar_t));
}

int polar_set(Polar_t *p, double radius, double angle)
{
	if (p == NULL) {
		return -1;
	}
	p->radius = radius;
	p->angle = angle;
	return 0;
}

double polar_get_radius(Polar_t *p)
{
	if (p == NULL) {
		return 0;
	}
	return p->radius;
}

double polar_get_angle(Polar_t *p)
{
	if (p == NULL) {
		return 0;
	}
	return p->angle;
}

int polar_set_radius(Polar_t *p, double radius)
{
	if (p == NULL) {
		return -1;
	}
	p->radius = radius;
	return 0;
}

int polar_set_angle(Polar_t *p, double angle)
{
	if (p == NULL) {
		return -1;
	}
	p->angle = angle;
	return 0;
}

int polar_compare(Polar_t *p1, Polar_t *p2)
{
	if (p1 == NULL || p2 == NULL) {
		return -1;
	}

	if (polar_get_radius(p1) == polar_get_radius(p2) &&
		polar_get_angle(p1) == polar_get_angle(p2)) {
		return 0;
	} else {
		return 1;
	}
}

int polar_to_complex(Polar_t *p, Complex_t *c)
{
	if (c == NULL || p == NULL) {
		return -1;
	}

	c->real = polar_get_radius(p) * cos(polar_get_angle(p));
	c->imag = polar_get_radius(p) * sin(polar_get_angle(p));

	return 0;
}

int polar_print(Polar_t *p)
{
	if (p == NULL) {
		return -1;
	}

	printf("%lf |_ %lf", polar_get_radius(p), polar_get_angle(p));
	return 0;
}

int polar_delete(Polar_t *p)
{
	if (p == NULL) {
		return -1;
	}

	free(p);
	p = NULL;
	return 0;
}
