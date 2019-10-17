/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:19:25 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/17 12:55:33 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int				i;
	int				j;
}				t_point;
typedef struct	s_figure
{
	t_point	*points;
	int		n;
}				t_figure;
typedef struct	s_row
{
	char	*line;
	int		line_len;
	int		n;
}				t_row;

char		**create_square(int size, t_dlist *answ);
void		print_square(char **sq, size_t size);
void		delete_square(char ***matrix, int size);
void		delete_matrix(t_dlist **lst);
int			add_row(t_dlist **matr, t_point pos, t_dlist *tetr, size_t n);
t_dlist		*create_matrix(size_t sq_size, t_dlist *tetr);
size_t		read_tetriminos(char *fname, t_dlist **figures);
int			is_correct_figure(t_point *m_point);
t_point		*check_simbols(char *str, t_point *m_point);
int			heck_figure(t_dlist **figures, char *str, size_t count);
int			push_tetriminos(t_dlist **figures, t_point *m_point, size_t n);
int			fillit_dlst_cmp(t_dlist *dl1, t_dlist *dl2);
int			check_figure(t_dlist **figures, char *str, size_t count);
size_t		find_square(char *fname, char ***sq);

void		pr(t_dlist *matr);
#endif
