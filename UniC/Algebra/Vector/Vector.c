//
// Created by andre on 4/22/2023.
//

#include "Vector.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static Vector2	AllocateVector2(void)
{
	return (Vector2)malloc(sizeof(Vector_2));
}

static Vector3	AllocateVector3(void)
{
	return (Vector3)malloc(sizeof(Vector_3));
}

Vector2	Vector2_init(VectorType x, VectorType y)
{
	Vector2	vector;

	vector = AllocateVector2();
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}

Vector3	Vector3_init(VectorType x, VectorType y, VectorType z)
{
	Vector3	vector;

	vector = AllocateVector3();
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

Vector2	Vector2_Sum(Vector2 v, Vector2 v2)
{
	return (Vector2_init(v->x + v2->x, v->y + v2->y));
}

Vector3	Vector3_Sum(Vector3 v, Vector3 v2)
{
	return (Vector3_init(v->x + v2->x, v->y + v2->y, v->z + v2->z));
}

Vector2	Vector2_Mul(VectorType num, Vector2 v)
{
	return (Vector2_init(num * (v->x), num * (v->y)));
}

Vector3	Vector3_Mul(VectorType num, Vector3 v)
{
	return (Vector3_init(v->x *= num, v->y *= num, v->z *= num));
}

VectorType	Vector2_ScalarProduct(Vector2 v, Vector2 v2)
{
	return (v->x * v2->x + v2->y * v2->y);
}

VectorType	Vector3_ScalarProduct(Vector3 v, Vector3 v2)
{
	return (v->x * v2->x + v2->y * v2->y + v->z * v2->z);
}

Vector3	Vector3_VectorialProduct(Vector3 v, Vector3 v2)
{
	return (Vector3_init(v->y * v2->z + v->z * v2->y, v->z * v2->x + v->x
			* v2->z, v->x * v2->y + v->y * v2->x));
}

VectorType	Vector2_Module(Vector2 v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2)));
}

VectorType	Vector3_Module(Vector3 v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}

Vector2	Vector2_Normalized(Vector2 v)
{
	const VectorType	module = Vector2_Module(v);

	return (Vector2_init(v->x / module, v->y / module));
}

Vector3	Vector3_Normalized(Vector3 v)
{
	const VectorType	module = Vector3_Module(v);

	return Vector3_init(v->x / module, v->y / module, v->z / module);
}

void	Vector2_Print(Vector2 v)
{
	printf("Vector:\nx: %lf y: %lf\n", v->x, v->y);
}

void	Vector3_Print(Vector3 v)
{
	printf("Vector:\nx: %lf y: %lf z: %lf\n", v->x, v->y, v->z);
}

void	Vector2_Free(Vector2 v)
{
	free(v);
}

void	Vector3_Free(Vector3 v)
{
	free(v);
}
