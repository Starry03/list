//
// Created by andre on 4/22/2023.
//

# include "unic/vector.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static t_vector2	allocate_vector2(void)
{
	return ((t_vector2)malloc(sizeof(t_vector2_)));
}

static t_vector3	allocate_vector3(void)
{
	return ((t_vector3)malloc(sizeof(t_vector3_)));
}

t_vector2	vector2_init(t_vector_type x, t_vector_type y)
{
	t_vector2	vector;

	vector = allocate_vector2();
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}

t_vector3	vector3_init(t_vector_type x, t_vector_type y, t_vector_type z)
{
	t_vector3	vector;

	vector = allocate_vector3();
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector2	vector2_sum(t_vector2 v, t_vector2 v2)
{
	return (vector2_init(v->x + v2->x, v->y + v2->y));
}

t_vector3	vector3_sum(t_vector3 v, t_vector3 v2)
{
	return (vector3_init(v->x + v2->x, v->y + v2->y, v->z + v2->z));
}

t_vector2	vector2_mul(t_vector_type num, t_vector2 v)
{
	return (vector2_init(num * (v->x), num * (v->y)));
}

t_vector3	vector3_mul(t_vector_type num, t_vector3 v)
{
	return (vector3_init(v->x *= num, v->y *= num, v->z *= num));
}

t_vector_type	vector2_scalarproduct(t_vector2 v, t_vector2 v2)
{
	return (v->x * v2->x + v2->y * v2->y);
}

t_vector_type	vector3_scalarproduct(t_vector3 v, t_vector3 v2)
{
	return (v->x * v2->x + v2->y * v2->y + v->z * v2->z);
}

t_vector3	vector3_vectorialproduct(t_vector3 v, t_vector3 v2)
{
	return (vector3_init(v->y * v2->z + v->z * v2->y, v->z * v2->x + v->x
			* v2->z, v->x * v2->y + v->y * v2->x));
}

t_vector_type	vector2_module(t_vector2 v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2)));
}

t_vector_type	vector3_module(t_vector3 v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}

t_vector2	vector2_normalized(t_vector2 v)
{
	const t_vector_type	module = vector2_module(v);

	return (vector2_init(v->x / module, v->y / module));
}

t_vector3	vector3_normalized(t_vector3 v)
{
	const t_vector_type	module = vector3_module(v);

	return (vector3_init(v->x / module, v->y / module, v->z / module));
}

void	vector2_print(t_vector2 v)
{
	printf("Vector:\nx: %lf y: %lf\n", v->x, v->y);
}

void	vector3_print(t_vector3 v)
{
	printf("Vector:\nx: %lf y: %lf z: %lf\n", v->x, v->y, v->z);
}

void	vector2_free(t_vector2 v)
{
	free(v);
}

void	vector3_free(t_vector3 v)
{
	free(v);
}
