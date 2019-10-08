/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:05:06 by marvin            #+#    #+#             */
/*   Updated: 2019/10/07 18:05:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
int		tetriminos_cmp(t_dlist *t1, t_dlist *t2)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
	}
}

size_t	calc_identical_tetriminos(t_dlist **tetriminos)
{
	t_dlist	*tmp;
	size_t	res;

	res = 0;
	tmp = *tetriminos;
	while (tetriminos_cmp(tmp, *tetriminos) == 1)
	{
		res++;
		*tetriminos = (*tetriminos)->next;
	}
	*tetriminos = (*tetriminos)->prev;
	return (res);
}*/
#include <stdio.h>

int		can_be_placed(char **sq, size_t sq_s, t_point *tetr, t_point pos)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		if (pos.i + tetr[i].i >= sq_s || pos.i + tetr[i].i < 0 ||
			pos.j + tetr[i].j >= sq_s || pos.j + tetr[i].j < 0)
			return (0);
		i++;
	}
	return (1);
}

t_dlist	*tetr_pos(char **square, size_t sq_size, t_point *tetr, size_t n)
{
	t_dlist	*res;
	size_t	i;
	size_t	j;
	size_t	f;
	t_point	pos;

	res = NULL;
	i = 0;
	while (i < sq_size)
	{
		j = 0;
		while (j < sq_size)
		{
			pos.i = i;
			pos.j = j;
			f = 0;
			if (can_be_placed(square, sq_size, tetr, pos) == 1)
				while (f++ < n)
					add_row(&res, pos, tetr, sq_size);
			j++;
		}
		i++;
	}
	return (res);
}

void pr(t_dlist *matr)
{
	t_dlist *tmp;
	t_dlist *row;
	
	tmp = matr;
	
	while (tmp != NULL)
	{
		row = (t_dlist *)(tmp->content);
		while (row != NULL)
		{
			printf("%c", *((char*)row->content));
			row = row->next;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

t_dlist	*create_matrix(size_t sq_size, t_dlist *tetr, char **sq)
{
	t_dlist	*matr;
	t_dlist	*tmp;
	size_t	n;

	matr = NULL;
	while (tetr != NULL)
	{
		ft_dlst_push_back(&matr, tetr_pos(sq, sq_size, tetr->content, tetr->content_size));
		tetr = tetr->next;
	}
	return (matr);
}
