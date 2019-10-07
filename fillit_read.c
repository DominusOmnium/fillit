/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/07 18:20:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int check_figure(t_dlist **figures, char *str)
{
	t_point	*m_point;
	int		i;
	int		j;
	int		c;
	
	m_point = (t_point*)ft_memalloc(sizeof(t_point) * 4);
	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[4 * i + j] != '#' && str[4 * i + j] != '.')
				return (-1);
			if (str[4 * i + j] == '#')
			{
				m_point[c].i = i;
				m_point[c].j = j;
				c++;
			}
			j++;
		}
		i++;
	}
	c = 0;
	i = m_point[0].i;
	j = m_point[0].j;
	while (c < 4)
	{
		m_point[c].i = m_point[c].i - i;
		m_point[c].j = m_point[c].j - j;
		c++;
	}
	ft_dlst_push_back(figures, ft_dlst_create_elem((void*)m_point));
}

int	fillit_read(t_dlist **figures, char *fname)
{
	int		fd;
	int		i;
	char	*str;
	char	*new;
	
	str = ft_strnew(16);
	fd = open(fname, O_RDONLY);
	new = str;
	while (1)
	{
		i = 0;
		while (i < 4)
		{
			if (read(fd, str, 5) == 0)
				return (0);
			if (str[4] != '\n')
				return (-1);
			str += 4;
			i++;
		}
		if (check_figure(figures, new) == -1)
			return (-1);
		if (read(fd, str, 1) != 0 && *str != '\n')	
			return (-1);
	}
}

t_dlist *read_tetriminos(char fname)
{
	t_dlist *figures;

	fillit_read(&figures, fname);
}

int main()
{
	t_dlist *lst = NULL;
	char str[] = ".....#...##..#..";
	printf("%d\n", check_figure(&lst, str));
}
