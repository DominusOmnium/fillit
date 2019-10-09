/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:02:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/09 15:37:15 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		find_best_col(t_dlist *matr, size_t n)
{
	size_t	i;
	size_t	min;
	int		ind;
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
	ind = -1;
	while (++i < n)
		if (sums[i] != 0 && sums[i] < min)
		{
			min = sums[i];
			ind = i;
		}
	ft_memdel((void**)&sums);
	return (ind);
}

void	remove_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ, t_dlist *row)
{
	int		ind[4];
	size_t	i;
	size_t	j;
	t_dlist	*tmp;

	i = -1;
	j = 0;
	ft_dlst_push_front(answ, row);
	while (++i < (*answ)->content_size)
		if (((char*)((*answ)->content))[i] == '1')
			ind[j++] = i;
	tmp = *matr;
	while ((tmp = tmp->next) != NULL)
	{
		if (((char*)tmp->content)[ind[0]] == '1' ||
			((char*)tmp->content)[ind[1]] == '1' ||
			((char*)tmp->content)[ind[2]] == '1' ||
			((char*)tmp->content)[ind[3]] == '1')
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->prev = NULL;
			ft_dlst_push_front(rm, tmp);
		}
	}
}

void	add_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ)
{
	t_dlist	*tmp;
	
	ft_dlst_push_front(matr, ft_dlst_popi(answ, 0));
	while ((tmp = ft_dlst_popi(rm, 0)) != -1)
		ft_dlst_push_back(matr, tmp);
}

int		can_fill(t_dlist **matr, char **sq, t_dlist **answ, size_t n)
{
	size_t	col;
	t_dlist	*removed;
	t_dlist	*tmp;

	if ((col = find_best_col(matr, n * n)) == -1)
		return (0);
	tmp = *matr;
	while (tmp != NULL)
	{
		if (((char*)tmp->content)[col] == '1')
		{
			tmp->prev = NULL;
			remove_rows(matr, &removed, answ, tmp);
			if (can_fill(matr, sq, answ, n) == 1)
				break ;
			else
				add_rows(matr, &removed, answ);
		}
		tmp = tmp->next;
	}
}

size_t	find_square(char *fname, char ***sq)
{
	size_t	sq_size;
	t_dlist	*tet;
	t_dlist	*matr;
	t_dlist	*answ;

	sq_size = read_tetriminos(fname, &tet);
	if (sq_size == 0)
		return (0);
	while (1)
	{
		*sq = create_square(sq_size);
		matr = create_matrix(sq_size, tet, *sq);
		answ = NULL;
		if (can_fill(&matr, sq, &answ, sq_size) == 1)
			break ;
		delete_square(sq, sq_size);
		del_matrix(&matr);
		sq_size++;
	}
	del_matrix(&matr);
	return (sq_size);
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
