#include "Complex.h"
#include <math.h>
#include <stdlib.h>

/**
 * @brief 
 */
t_complex	Complex_Init(t_complex_type re, t_complex_type im)
{
	t_complex	c;

	c = (t_complex)malloc(sizeof(t_complex_));
	if (!c)
		return (NULL);
	c->re = re;
	c->im = im;
	return (c);
}

void	Complex_free(t_complex c)
{
	free(c);
}

t_complex_type	Complex_mod(t_complex c)
{
	t_complex_type	re;
	t_complex_type	im;

	re = c->re;
	im = c->im;
	return (sqrt(re * re + im * im));
}

t_complex	Complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c = Complex_Init(a->re + b->re, a->im + b->im);
	return (c);
}

t_complex	Complex_sub(t_complex a, t_complex b)
{
	t_complex	c;

	c = Complex_Init(a->re - b->re, a->im - b->im);
	return (c);
}
t_complex	Complex_mul(t_complex a, t_complex b)
{
	return (Complex_Init(a->re * b->re - a->im * b->im, a->re * b->im + a->im
			* b->re));
}
t_complex	Complex_div(t_complex a, t_complex b)
{
	t_complex_type mod;

	mod = Complex_mod(b);
	return (Complex_Init((a->re * b->re + a->im * b->im) / mod, (a->im * b->re
				- a->re * b->im) / mod));
}
