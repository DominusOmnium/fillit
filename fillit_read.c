/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/16 22:30:57 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*t_figure	*new_el(t_point	*m_point, int n)
{
	t_figure *new;

	if ((new = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (NULL);
	new->points = m_point;
	new->n = n;
	return (new);
}*/

int		push_tetriminos(t_dlist **figures, t_point *m_point, size_t n)
{
	t_dlist	*new;

	/*new = *figures;
	while (new != NULL)
	{
		if (((t_point*)(new->content))[0].i == m_point[0].i &&
			((t_point*)(new->content))[0].j == m_point[0].j &&
			((t_point*)(new->content))[1].i == m_point[1].i &&
			((t_point*)(new->content))[1].j == m_point[1].j &&
			((t_point*)(new->content))[2].i == m_point[2].i &&
			((t_point*)(new->content))[2].j == m_point[2].j &&
			((t_point*)(new->content))[3].i == m_point[3].i &&
			((t_point*)(new->content))[3].j == m_point[3].j)
		{
			ft_realloc(new->content, new->content_size * sizeof(t_figure),
				(new->content_size + 1) * sizeof(t_figure));
			((t_figure*)(new->content))[new->content_size].points = m_point;
			((t_figure*)(new->content))[new->content_size].n = n;
			new->content_size += 1;
			break ;
		}
		new = new->next;
	}
	if (new == NULL)
	{
		ft_dlst_push_front(figures,
					ft_dlst_create_elem((void*)(new_el(m_point, (int)n))));
		(*figures)->content_size = 1;
	}*/
	if ((new = ft_dlst_create_elem(m_point)) == NULL)
		return (0);
	new->content_size = n;
	ft_dlst_push_back(figures, new);
}

size_t	read_tetr_cycle(char *str, int fd, t_dlist **figures)
{
	int		i;
	size_t	res;
	char	*new;

	res = 0;
	new = str;
	while (1)
	{
		str = new;
		i = 0;
		while (i++ < 4)
		{
			if (read(fd, str, 5) == 0)
				return (res);
			if (str[4] != '\n')
				return (0);
			str += 4;
		}
		if (check_figure(figures, new, (res + 1)) == -1)
			return (0);
		else
			res++;
		if (read(fd, str, 1) != 0 && *str != '\n')
			return (0);
	}
}

size_t	read_tetriminos(char *fname, t_dlist **figures)
{
	int		fd;
	char	*str;

	if ((str = ft_strnew(16)) == NULL)
		return (0);
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (0);
	return (read_tetr_cycle(str, fd, figures));
	ft_putendl("4");
}
