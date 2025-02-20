//
// Created by andre on 4/21/2023.
//

# include "unic/matrix.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define SQUARE_ERROR "Matrix is not square"
#define TWOBTWO_ERROR "Matrix is not 2x2"
#define SARRUS_ERROR "Matrix is not 3x3"
#define MATRIX_NULL (t_matrix) NULL

static t_mat_type	*init_row(size_t len)
{
	return (t_mat_type *)calloc(len, sizeof(t_mat_type));
}

static t_mat_type	**init_table(size_t y, size_t x)
{
	t_mat_type	**matrix;

	matrix = (t_mat_type **)malloc(y * sizeof(t_mat_type *));
	for (size_t i = 0; i < y; i++)
		matrix[i] = init_row(x);
	return (matrix);
}

t_matrix	matrix_init(size_t y, size_t x)
{
	t_matrix	matrix;

	matrix = (t_matrix)malloc(sizeof(t_mat));
	if (!matrix)
		return (MATRIX_NULL);
	matrix->table = init_table(y, x);
	matrix->cols = x;
	matrix->rows = y;
	return (matrix);
}

t_matrix	identity_matrix(size_t length, t_mat_type value)
{
	t_matrix	matrix;

	matrix = matrix_init(length, length);
	for (size_t i = 0; i < length; i++)
		for (size_t j = 0; j < length; j++)
			matrix_setvalue(matrix, kronecker_delta(i, j) * value, i, j);
	return (matrix);
}

inline bool	kronecker_delta(size_t i, size_t j)
{
	return (i == j);
}

void	matrix_setvalue(t_matrix matrix, t_mat_type value, size_t y, size_t x)
{
	if (!matrix)
		return ;
	matrix->table[y][x] = value;
}

t_mat_type	*matrix_getrow(t_matrix matrix, size_t n)
{
	if (!matrix)
		return (NULL);
	return (matrix->table[n]);
}

t_mat_type	*matrix_getcolumn(t_matrix matrix, size_t n)
{
	t_mat_type	*arr;

	arr = init_row(matrix->rows);
	for (size_t y = 0; y < matrix->rows; y++)
		arr[y] = matrix->table[y][n];
	return ((t_mat_type *)arr);
}

t_matrix	matrix_sum(t_matrix mat, t_matrix mat2)
{
	t_matrix	newMatrix;

	if (!mat || !mat2)
		return (MATRIX_NULL);
	newMatrix = matrix_init(mat->rows, mat->cols);
	if ((mat->rows != mat2->rows) || (mat->cols != mat2->cols))
	{
		printf("cannot be summed");
		return (newMatrix);
	}
	for (size_t y = 0; y < mat->rows; y++)
		for (size_t x = 0; x < mat->cols; x++)
			matrix_setvalue(newMatrix, mat->table[y][x] + mat2->table[y][x], y,
				x);
	return (newMatrix);
}

t_matrix	matrix_scalarproduct(t_matrix mat, t_mat_type scalar)
{
	t_matrix	newMatrix;

	newMatrix = matrix_init(mat->rows, mat->cols);
	for (size_t y = 0; y < mat->rows; y++)
		for (size_t x = 0; x < mat->cols; x++)
			matrix_setvalue(newMatrix, mat->table[y][x] * scalar, y, x);
	return (newMatrix);
}

t_matrix	matrix_product(t_matrix mat, t_matrix mat2)
{
	t_matrix	newMatrix;

	newMatrix = matrix_init(mat->rows, mat2->cols);
	if (mat->cols != mat2->rows)
	{
		printf("Cannot be multiplied, incompatible dimensions");
		return (newMatrix);
	}
	for (size_t y = 0; y < mat->rows; y++)
		for (size_t x = 0; x < mat->cols; x++)
			for (size_t k = 0; k < mat->cols; k++)
				newMatrix->table[y][x] += mat->table[y][k] * mat->table[k][x];
	return (newMatrix);
}

// y: index, length: mat->rows
// x: index, length: mat->cols
t_matrix	matrix_suppressed(t_matrix mat, size_t y, size_t x)
{
	const size_t	new_y = mat->rows - 1;
	const size_t	new_x = mat->cols - 1;
	size_t			x_count;
	size_t			y_count;
	t_matrix		subMatrix;

	x_count = 0;
	if (mat->rows < 2 && mat->cols < 2)
	{
		printf("Mat cannot be modified (insufficient size)");
		return (mat);
	}
	if (y >= mat->rows || x >= mat->cols)
	{
		printf("Mat cannot be modified (out of bounds)");
		return (mat);
	}
	x_count = 0, y_count = 0;
	subMatrix = matrix_init(new_y, new_x);
	for (size_t i = 0; i < mat->rows && y_count < new_y; i++)
	{
		for (size_t j = 0; j < mat->cols; j++)
		{
			if (i != y && j != x)
			{
				matrix_setvalue(subMatrix, mat->table[i][j], y_count,
					x_count++);
				if (x_count >= new_x)
				{
					x_count = 0;
					y_count++;
				}
			}
		}
	}
	return (subMatrix);
}

t_matrix	matrix_transpose(t_matrix mat)
{
	t_matrix	newMatrix;

	if (!mat)
		return (MATRIX_NULL);
	newMatrix = matrix_init(mat->cols, mat->rows);
	for (size_t row = 0; row < mat->rows; row++)
		for (size_t col = 0; col < mat->cols; col++)
			matrix_setvalue(newMatrix, mat->table[row][col], col, row);
	return (newMatrix);
}

t_mat_type	matrix_twobytwo_det(t_matrix mat)
{
	t_mat_type	**table;
	double		mainDiagonal;
	double		secondaryDiagonal;

	if (!mat || mat->rows != 2 || mat->cols != 2)
	{
		errno = EINVAL;
		perror(TWOBTWO_ERROR);
		return (0);
	}
	table = mat->table;
	mainDiagonal = table[0][0] * table[1][1];
	secondaryDiagonal = table[0][1] * table[1][0];
	return (mainDiagonal - secondaryDiagonal);
}

t_mat_type	matrix_sarrus_det(t_matrix mat)
{
	const t_mat_type	mainDiagonal = mat->table[0][0] * mat->table[1][1]
			* mat->table[2][2];
	const t_mat_type	secondaryDiagonal = mat->table[0][1] * mat->table[1][2]
			* mat->table[2][0];
	const t_mat_type	tertiaryDiagonal = mat->table[0][2] * mat->table[1][0]
			* mat->table[2][1];
	const t_mat_type	mainDiagonal2 = mat->table[0][2] * mat->table[1][1]
			* mat->table[2][0];
	const t_mat_type	secondaryDiagonal2 = mat->table[0][0] * mat->table[1][2]
			* mat->table[2][1];
	const t_mat_type	tertiaryDiagonal2 = mat->table[0][1] * mat->table[1][0]
			* mat->table[2][2];

	if (!mat || mat->rows != 3 || mat->cols != 3)
	{
		errno = EINVAL;
		perror(SARRUS_ERROR);
		return (0);
	}
	return (mainDiagonal + secondaryDiagonal + tertiaryDiagonal - mainDiagonal2
		- secondaryDiagonal2 - tertiaryDiagonal2);
}

/**
 * @brief Recursive function to calculate the determinant of a matrix
 * @param mat: Matrix to calculate the determinant
 *
 * @return The determinant of the matrix
 */
t_mat_type	matrix_laplace_det(t_matrix mat)
{
	t_mat_type	det;
	t_matrix	subMatrix;

	if (!mat)
		return (0);
	if (mat->rows != mat->cols)
	{
		errno = EINVAL;
		perror(SQUARE_ERROR);
		return (0);
	}
	if (mat->rows == 2)
		return (matrix_twobytwo_det(mat));
	if (mat->rows == 3)
		return (matrix_sarrus_det(mat));
	det = 0;
	for (size_t i = 0; i < mat->rows; i++)
	{
		subMatrix = matrix_suppressed(mat, 0, i);
		det += mat->table[0][i] * matrix_laplace_det(subMatrix) * (!(i & 1) ? 1 :
				-1);
		matrix_free(subMatrix);
	}
	return (det);
}

void	matrix_fill(t_matrix matrix, t_mat_type value, size_t y0, size_t x0)
{
	size_t	x0_copy;

	if (!matrix)
		return ;
	x0_copy = x0;
	while (y0 < matrix->rows)
	{
		while (x0 < matrix->cols)
		{
			matrix_setvalue(matrix, value, y0, x0);
			x0++;
		}
		y0++;
		x0 = x0_copy;
	}
}

void	matrix_print(t_matrix matrix)
{
	printf("Mat:\n");
	for (size_t y = 0; y < matrix->rows; y++)
	{
		for (size_t x = 0; x < matrix->cols; x++)
			printf("%lf\t", matrix->table[y][x]);
		printf("\n");
	}
}

void	matrix_free(t_matrix matrix)
{
	for (size_t i = 0; i < matrix->rows; i++)
		free(matrix->table[i]);
	free(matrix->table);
	free(matrix);
}

t_mat_type	matrix_getvalue(t_matrix matrix, size_t y, size_t x)
{
	return (matrix->table[y][x]);
}

t_matrix	matrix_inverse(t_matrix mat)
{
	t_matrix	newMatrix;
	t_matrix	sup;

	newMatrix = matrix_init(mat->cols, mat->rows);
	for (size_t i = 0; i < newMatrix->cols; i++)
		for (size_t j = 0; j < newMatrix->rows; j++)
		{
			sup = matrix_suppressed(mat, i, j);
			matrix_setvalue(newMatrix, matrix_laplace_det(sup), i, j);
			matrix_free(sup);
		}
	return (newMatrix);
}
