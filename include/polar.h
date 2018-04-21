/* OpenSignal
 * polar.h | polar.c header file
 * Dogan C. Karatas | 2018 | GNU GPL v3
 */
#ifndef __POLAR_H
#define __POLAR_H

Polar_t* polar(void);
int	polar_init(Polar_t *p, double radius, double angle);
double	polar_get_radius(Polar_t *p);
double	polar_get_angle(Polar_t *p);
int	polar_set_radius(Polar_t *p, double radius);
int	polar_set_angle(Polar_t *p, double angle);
int	polar_compare(Polar_t *p1, Polar_t *p2);
int	polar_to_complex(Polar_t *p, Complex_t *c);
int	polar_print(Polar_t *p);
int	polar_delete(Polar_t *p);

#endif /* __POLAR_H */
