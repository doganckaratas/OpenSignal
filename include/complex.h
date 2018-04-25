/* OpenSignal
 * complex.h | complex.c header file
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#ifndef __COMPLEX_H
#define __COMPLEX_H

Complex_t* complex_new(void);
int	complex_set(Complex_t *c, double i, double j);
double	complex_get_real(Complex_t *c);
double	complex_get_imag(Complex_t *c);
int	complex_set_real(Complex_t *c, double i);
int	complex_set_imag(Complex_t *c, double j);
int	complex_compare(Complex_t *c1, Complex_t *c2);
int	complex_to_polar(Complex_t *c, Polar_t *p);
int	complex_print(Complex_t *c);
int	complex_delete(Complex_t *c);

#endif /* __COMPLEX_H */
