//
// Created by andre on 4/22/2023.
//

#ifndef STARRY_VECTOR_H
#define STARRY_VECTOR_H

typedef double VectorType;

typedef struct Vector_2
{
    VectorType x;
    VectorType y;
} Vector_2;

typedef Vector_2 *Vector2;

typedef struct Vector_3
{
    VectorType x;
    VectorType y;
    VectorType z;
} Vector_3;

typedef Vector_3 *Vector3;

#define VECTOR2_ZERO InitVector2(0, 0)
#define VECTOR2_UP InitVector2(0, 1)
#define VECTOR2_RIGHT InitVector2(1, 0)
#define VECTOR3_RIGHT InitVector3(1, 0, 0)
#define VECTOR3_UP InitVector3(0, 1, 0)
#define VECTOR3_FORWARD InitVector3(0, 0, 1)
#define VECTOR3_ZERO InitVector3(0, 0, 0)
#define VECTOR3_ONE InitVector3(1, 1, 1)

Vector2 Vector2_init(VectorType x, VectorType y);

Vector3 Vector3_init(VectorType x, VectorType y, VectorType z);

Vector2 Vector2_Sum(Vector2 v, Vector2 v2);

Vector3 Vector3_Sum(Vector3 v, Vector3 v2);

Vector2 Vector2_Mul(VectorType num, Vector2 v);

Vector3 Vector3_Mul(VectorType num, Vector3 v);

VectorType Vector2_ScalarProduct(Vector2 v, Vector2 v2);

VectorType Vector3_ScalarProduct(Vector3 v, Vector3 v2);

Vector3 Vector3_VectorialProduct(Vector3 v, Vector3 v2);

VectorType Vector2_Module(Vector2 v);

VectorType Vector3_Module(Vector3 v);

Vector2 Vector2_Normalized(Vector2 v);

Vector3 Vector3_Normalized(Vector3 v);

void Vector2_Print(Vector2 v);

void Vector3_Print(Vector3 v);

void Vector2_Free(Vector2 v);

void Vector3_Free(Vector3 v);

#endif // STARRY_VECTOR_H
