//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_MATRIX_H
# define STARRY_MATRIX_H

# include <stdbool.h>
# include <stddef.h>

typedef double	Mat_type;
typedef struct
{
	Mat_type	**table;
	size_t		cols;
	size_t		rows;
}				Mat;

typedef Mat		*Matrix;

static Mat_type	*InitRow(size_t len);

static Mat_type	**InitTable(size_t y, size_t x);

Matrix			Matrix_Init(size_t y, size_t x);

Matrix			Identity_matrix(size_t length, Mat_type value);

bool			KroneckerDelta(size_t i, size_t j);

void			Matrix_SetValue(Matrix matrix, Mat_type value, size_t y,
					size_t x);

Mat_type		Matrix_GetValue(Matrix matrix, size_t y, size_t x);

Mat_type		*Matrix_GetColumn(Matrix matrix, size_t n);

Mat_type		*Matrix_GetRow(Matrix matrix, size_t n);

Matrix			Matrix_Sum(Matrix mat, Matrix mat2);

Matrix			Matrix_ScalarProduct(Matrix mat, Mat_type scalar);

Matrix			MatrixProduct(Matrix mat, Matrix mat2);

Matrix			Matrix_Suppressed(Matrix mat, size_t y, size_t x);

Matrix			Matrix_Transpose(Matrix mat);

Mat_type		Matrix_TwoByTwoDet(Matrix mat);

Mat_type		Matrix_SarrusDet(Matrix mat);

Mat_type		Matrix_LaplaceDet(Matrix mat);

Matrix			Matrix_Inverse(Matrix mat);

void			Matrix_Fill(Matrix matrix, Mat_type value, size_t y0,
					size_t x0);

void			Matrix_Print(Matrix matrix);

void			Matrix_Free(Matrix matrix);

#endif // STARRY_MATRIX_H
