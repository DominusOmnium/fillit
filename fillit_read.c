/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/09 16:17:59 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	push_tetriminos(t_dlist **figures, t_point *m_point)
{
	t_dlist	*new;

	new = *figures;
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
			new->content_size += 1;
			break ;
		}
		new = new->next;
	}
	if (new == NULL)
	{
		ft_dlst_push_front(figures, ft_dlst_create_elem((void*)m_point));
		(*figures)->content_size = 1;
	}
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
		if (check_figure(figures, new) == -1)
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
	int		i;
	size_t	res;
	char	*str;
	char	*new;

	str = ft_strnew(16);
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (0);
	return (read_tetr_cycle(str, fd, figures));
}

int main()
{
	size_t res;
	t_dlist *figures;
	t_dlist *pr;

	figures = NULL;
	char fname[9] = "in.txt";

	res = read_tetriminos(fname, &figures);
	printf("%zu\n", res);
	/*int i = 0;
	pr = figures;
	while (pr != NULL)
	{
		printf("%d\n", pr->content_size);
		int j = 0;
	while (j < 4)
	{
		printf("%d - s element \n", j);
		printf("%d\n", ((t_point*)(pr->content))[j].i);
		printf("%d\n", ((t_point*)(pr->content))[j].j);
		j++;
	}
	printf("\n");
	pr = pr->next;
	}*/
}
