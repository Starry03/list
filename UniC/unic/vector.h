//
// Created by andre on 4/22/2023.
//

#ifndef STARRY_VECTOR_H
# define STARRY_VECTOR_H

typedef double		t_vector_type;

typedef struct s_vector2
{
	t_vector_type	x;
	t_vector_type	y;
}					t_vector2_;

typedef t_vector2_	*t_vector2;

typedef struct s_vector3
{
	t_vector_type	x;
	t_vector_type	y;
	t_vector_type	z;
}					t_vector3_;

typedef t_vector3_	*t_vector3;

# define VECTOR2_ZERO vector2_init(0, 0)
# define VECTOR2_UP vector2_init(0, 1)
# define VECTOR2_LEFT vector2_init(-1, 0)
# define VECTOR2_RIGHT vector2_init(1, 0)
# define VECTOR2_DOWN vector2_init(0, -1)
# define VECTOR2_ONE vector2_init(1, 1)
# define VECTOR3_LEFT vector3_init(-1, 0, 0)
# define VECTOR3_DOWN vector3_init(0, -1, 0)
# define VECTOR3_BACK vector3_init(0, 0, -1)
# define VECTOR3_RIGHT vector3_init(1, 0, 0)
# define VECTOR3_UP vector3_init(0, 1, 0)
# define VECTOR3_FORWARD vector3_init(0, 0, 1)
# define VECTOR3_ZERO vector3_init(0, 0, 0)
# define VECTOR3_ONE vector3_init(1, 1, 1)

t_vector2			vector2_init(t_vector_type x, t_vector_type y);

t_vector3			vector3_init(t_vector_type x, t_vector_type y,
						t_vector_type z);

t_vector2			vector2_sum(t_vector2 v, t_vector2 v2);

t_vector3			vector3_sum(t_vector3 v, t_vector3 v2);

t_vector2			vector2_mul(t_vector_type num, t_vector2 v);

t_vector3			vector3_mul(t_vector_type num, t_vector3 v);

t_vector_type		vector2_scalarproduct(t_vector2 v, t_vector2 v2);

t_vector_type		vector3_scalarproduct(t_vector3 v, t_vector3 v2);

t_vector3			vector3_vectorialproduct(t_vector3 v, t_vector3 v2);

t_vector_type		vector2_module(t_vector2 v);

t_vector_type		vector3_module(t_vector3 v);

t_vector2			vector2_normalized(t_vector2 v);

t_vector3			vector3_normalized(t_vector3 v);

void				vector2_print(t_vector2 v);

void				vector3_print(t_vector3 v);

void				vector2_free(t_vector2 v);

void				vector3_free(t_vector3 v);

#endif
