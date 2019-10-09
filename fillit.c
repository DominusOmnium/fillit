/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:02:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/09 14:01:49 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		find_best_col(t_dlist *matr, size_t n)
{
	size_t	i;
	size_t	min;
	size_t	ind;
	int		*sums;

	if ((sums = (int*)ft_memalloc(n * sizeof(int))) == NULL)
		return (-1);
	while (matr != NULL)
	{
		i = -1;
		while (++i < n)
			if (((char*)matr->content)[i] == '1')
				sums[i]++;
	}
	i = -1;
	min = -1;
	while (++i < n)
		if (sums[i] < min)
		{
			min = sums[i];
			ind = i;
		}
	return (ind);
}

t_dlist	*remove_rows(t_dlist **matr, t_dlist **removed, size_t row)
{
	int		ind[4];
	size_t	i;
	size_t	j;
	t_dlist	*tmp;

	i = 0;
	j = 0;
	tmp = ft_dlst_geti(*matr, row);
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	while (i < tmp->content_size)
	{
		if (((char*)(tmp->content))[i] == '1')
			ind[j++] = i;
		i++;
	}
	while ((tmp = tmp->next) != NULL)
	{
		if (((char*)tmp->content)[ind[0]] == '1' ||
			((char*)tmp->content)[ind[1]] == '1' ||
			((char*)tmp->content)[ind[2]] == '1' ||
			((char*)tmp->content)[ind[3]] == '1')
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			ft_dlst_push_front(removed, tmp);
		}
	}
}

int		can_fill(t_dlist *matr, char **sq, t_dlist **resh, size_t n)
{
	size_t	col;
	t_dlist	*removed;

	while (matr != NULL)
	{
	}
	removed = NULL;
}

size_t	find_square(char *fname, char **sq)
{
	size_t	sq_size;
	t_dlist	*tet;
	t_dlist	*matr;

	sq_size = read_tetriminos(fname, &tet);
	if (sq_size == 0)
		return (0);
	while (1)
	{
		sq = create_square(sq_size);
		matr = create_matrix(sq_size, tet, sq);
		if (can_fill(matr, sq, sq_size) == 1)
			break ;
		delete_square(sq, sq_size);
		del_matrix(&matr);
		sq_size++;
	}
}

int		main(int ac, char **av)
{
	char	**sq;
	size_t	res;
	size_t	i;
	size_t	j;

	if (ac != 2)
	{
		ft_putendl("Error");
		return (0);
	}
	if ((res = find_square(av[1], sq)) == 0)
	{
		ft_putendl("Error");
		return (0);
	}
	i = 0;
	while (i < res)
		ft_putendl(sq[i++]);
	return (0);
}
