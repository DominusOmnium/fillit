/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:19:25 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/07 18:07:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <io.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int				i;
	int				j;
}				t_point;
char		**create_square(size_t size);
void		delete_square(char **matrix, size_t size);
void		del_col(t_dlist *lst, size_t col);
void		del_row(t_dlist **lst, size_t col);
void		del_matrix(t_dlist **lst);
int			add_row(t_dlist **matr, t_point pos, t_point *tetrimino, size_t n);
t_dlist		*create_matrix(size_t sq_size, t_dlist *tetr, char **sq);
size_t		read_tetriminos(char *fname, t_dlist **figures);
//t_dlist		*read_tetriminos(char *fname);
void		pr(t_dlist *matr);
#endif
