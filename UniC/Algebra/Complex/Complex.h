#ifndef COMPLEX_H
# define COMPLEX_H

typedef double			t_complex_type;

typedef struct s_complex
{
	t_complex_type		re;
	t_complex_type		im;
}						t_complex_;

typedef t_complex_		*t_complex;

t_complex				complex_init(t_complex_type re, t_complex_type im);
void					complex_free(t_complex c);
t_complex_type			complex_mod(t_complex c);
t_complex				complex_add(t_complex a, t_complex b);
t_complex				complex_sub(t_complex a, t_complex b);
t_complex				complex_mul(t_complex a, t_complex b);
t_complex				complex_div(t_complex a, t_complex b);

#endif