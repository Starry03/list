#ifndef COMPLEX_H
# define COMPLEX_H

typedef double			t_complex_type;

typedef struct s_complex
{
	t_complex_type		re;
	t_complex_type		im;
}						t_complex_;

typedef t_complex_		*t_complex;

t_complex				Complex_Init(t_complex_type re, t_complex_type im);
void					Complex_free(t_complex c);
t_complex_type			Complex_mod(t_complex c);
t_complex				Complex_add(t_complex a, t_complex b);
t_complex				Complex_sub(t_complex a, t_complex b);
t_complex				Complex_mul(t_complex a, t_complex b);
t_complex				Complex_div(t_complex a, t_complex b);

#endif