/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/17 15:41:00 by dkathlee         ###   ########.fr       */
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
	int		rd;
	size_t	res;
	char	*new;

	res = 0;
	new = str;
	while (1)
	{
		i = 0;
		while (i++ < 4)
		{
			if ((rd = read(fd, str, 5)) < 5)
				return (0);
			if (str[4] != '\n')
				return (0);
			str += 4;
		}
		if (check_figure(figures, new, (res + 1)) == -1)
			return (0);
		else
			res++;
		str = new;
		if ((rd = read(fd, str, 1)) != 0 && *str != '\n')
			return (0);
		if (rd == 0)
			return (res);
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
}
