# include "unic/complex.h"
#include <math.h>
#include <stdlib.h>

/**
 * @brief
 */
t_complex	complex_init(t_complex_type re, t_complex_type im)
{
	t_complex	c;

	c = (t_complex)malloc(sizeof(t_complex_));
	if (!c)
		return (NULL);
	c->re = re;
	c->im = im;
	return (c);
}

void	complex_free(t_complex c)
{
	free(c);
}

t_complex_type	complex_mod(t_complex c)
{
	t_complex_type	re;
	t_complex_type	im;

	re = c->re;
	im = c->im;
	return (sqrt(re * re + im * im));
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c = complex_init(a->re + b->re, a->im + b->im);
	return (c);
}

t_complex	complex_sub(t_complex a, t_complex b)
{
	t_complex	c;

	c = complex_init(a->re - b->re, a->im - b->im);
	return (c);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	return (complex_init(a->re * b->re - a->im * b->im, a->re * b->im + a->im
			* b->re));
}

t_complex	complex_div(t_complex a, t_complex b)
{
	t_complex_type	mod;

	mod = complex_mod(b);
	return (complex_init((a->re * b->re + a->im * b->im) / mod, (a->im * b->re
				- a->re * b->im) / mod));
}
