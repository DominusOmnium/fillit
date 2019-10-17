/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/17 16:44:44 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		push_tetriminos(t_dlist **figures, t_point *m_point, size_t n)
{
	t_dlist	*new;

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
		i = 0;
		while (i++ < 4)
		{
			if ((read(fd, str, 5) < 5) || (str[4] != '\n'))
				return (0);
			str += 4;
		}
		res++;
		str = new;
		if ((check_figure(figures, new, res) == -1) ||
					((i = read(fd, str, 1)) != 0 && *str != '\n'))
			return (0);
		if (i == 0)
			break ;
	}
	return (res);
}

size_t	read_tetriminos(char *fname, t_dlist **figures)
{
	int		fd;
	char	*str;
	int		res;

	if ((str = ft_strnew(16)) == NULL)
		return (0);
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (0);
	res = read_tetr_cycle(str, fd, figures);
	if (res == 0)
	{
		free(str);
		ft_dlst_delete(figures);
	}
	return (res);
}
