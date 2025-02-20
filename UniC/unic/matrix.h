//
// Created by andre on 4/13/2023.
//

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include <stddef.h>

typedef double		t_mat_type;
typedef struct s_mat
{
	t_mat_type		**table;
	size_t			cols;
	size_t			rows;
}					t_mat;

typedef t_mat		*t_matrix;

static t_mat_type	*init_row(size_t len);

static t_mat_type	**init_table(size_t y, size_t x);

t_matrix			matrix_init(size_t y, size_t x);

t_matrix			identity_matrix(size_t length, t_mat_type value);

bool				kronecker_delta(size_t i, size_t j);

void				matrix_setvalue(t_matrix matrix, t_mat_type value, size_t y,
						size_t x);

t_mat_type			matrix_getvalue(t_matrix matrix, size_t y, size_t x);

t_mat_type			*matrix_getcolumn(t_matrix matrix, size_t n);

t_mat_type			*matrix_getrow(t_matrix matrix, size_t n);

t_matrix			matrix_sum(t_matrix mat, t_matrix mat2);

t_matrix			matrix_scalarproduct(t_matrix mat, t_mat_type scalar);

t_matrix			matrix_product(t_matrix mat, t_matrix mat2);

t_matrix			matrix_suppressed(t_matrix mat, size_t y, size_t x);

t_matrix			matrix_transpose(t_matrix mat);

t_mat_type			matrix_twobytwo_det(t_matrix mat);

t_mat_type			matrix_sarrus_det(t_matrix mat);

t_mat_type			matrix_laplace_det(t_matrix mat);

t_matrix			matrix_inverse(t_matrix mat);

void				matrix_fill(t_matrix matrix, t_mat_type value, size_t y0,
						size_t x0);

void				matrix_print(t_matrix matrix);

void				matrix_free(t_matrix matrix);

#endif
