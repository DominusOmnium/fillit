/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/09 12:07:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check(t_point *m_point)
{
	int c;

	c = 0;
	if (((ABS((m_point[0].i - m_point[1].i)) + ABS((m_point[0].j
		- m_point[1].j))) == 1 || (ABS((m_point[0].i - m_point[2].i)) +
		ABS((m_point[0].j - m_point[2].j))) == 1 || (ABS((m_point[0].i -
		m_point[3].i)) + ABS((m_point[0].j - m_point[3].j))) == 1))
			c++;
	if (((ABS((m_point[1].i - m_point[2].i)) +
		ABS((m_point[1].j - m_point[2].j))) == 1 || (ABS((m_point[1].i -
		m_point[3].i)) + ABS((m_point[1].j - m_point[3].j))) == 1))
			c++;
	if (((ABS((m_point[2].i - m_point[3].i)) +
		ABS((m_point[2].j - m_point[3].j))) == 1))
			c++;
	else
		return (-1);
	if (c < 3)
		return (-1);
	return (c);
}

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

t_point	*check_simbols(char *str, t_point *m_point)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[4 * i + j] != '#' && str[4 * i + j] != '.')
				return (NULL);
			if (str[4 * i + j] == '#')
			{
				m_point[c].i = i;
				m_point[c++].j = j;
			}
			j++;
		}
		i++;
	}
	if (c != 4)
		return (NULL);
	return (m_point);
}

int		check_figure(t_dlist **figures, char *str)
{
	t_point	*m_point;
	int		i;
	int		j;
	int		c;
	
	m_point = (t_point*)ft_memalloc(sizeof(t_point) * 4);
	if ((m_point = check_simbols(str, m_point)) == NULL)
		return (-1);
	c = 0;
	i = m_point[0].i;
	j = m_point[0].j;
	while (c < 4)
	{
		m_point[c].i = m_point[c].i - i;
		m_point[c].j = m_point[c].j - j;
		c++;
	}
	if (check(m_point) != -1)
		push_tetriminos(figures, m_point);
	else
		return (-1);
	return (0);
}

size_t	read_tetriminos(char *fname, t_dlist **figures)
{
	int		fd;
	int		i;
	size_t	res;
	char	*str;
	char	*new;
	
	res = 0;
	str = ft_strnew(16);
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (0);
	new = str;
	while (1)
	{
		str = new;
		i = 0;
		while (i < 4)
		{
			if (read(fd, str, 6) == 0)
				return (res);
			if (str[4] != 10)
				return (0);
			str += 4;
			i++;
		}
		if (check_figure(figures, new) == -1)
			return (0);
		else
			res++;
		if (read(fd, str, 1) != 0 && *str != '\n')
			return (0);
	}
}

int main()
{
	size_t res;
	t_dlist *figures;
	t_dlist *pr;
	
	figures = NULL;
	char fname[9] = "Proverka";

	res = read_tetriminos(fname, &figures);
	printf("%d\n", res);
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
