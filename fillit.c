/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:02:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/09 18:26:25 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
/*
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
			if ((((t_row*)matr->content)->line)[i] == '1')
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
*/
void	remove_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ, int row)
{
	int		ind[4];
	size_t	i;
	size_t	j;
	t_dlist	*tmp;

	i = -1;
	j = 0;
	ft_dlst_push_front(answ, ft_dlst_popi(matr, i));
	while (++i < (*answ)->content_size)
		if ((((t_row*)((*answ)->content))->line)[i] == '1')
			ind[j++] = i;
	tmp = *matr;
	while ((tmp = tmp->next) != NULL)
	{
		if ((((t_row*)(tmp->content))->line)[ind[0]] == '1' ||
			(((t_row*)(tmp->content))->line)[ind[1]] == '1' ||
			(((t_row*)(tmp->content))->line)[ind[2]] == '1' ||
			(((t_row*)(tmp->content))->line)[ind[3]] == '1')
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
	while ((tmp = ft_dlst_popi(rm, 0)) != NULL)
		ft_dlst_push_back(matr, tmp);
}

int		can_fill(t_dlist **matr, char **sq, t_dlist **answ, size_t n)
{
	size_t	col;
	t_dlist	*removed;
	t_dlist	*tmp;
	tmp = *matr;
	while (tmp != NULL)
	{
			tmp->prev = NULL;
			remove_rows(matr, &removed, answ, ((t_row*)tmp->content)->n);
			if (can_fill(matr, sq, answ, n) == 1)
				break ;
			else
				add_rows(matr, &removed, answ);
		tmp = tmp->next;
	}
}
/*
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
		if (can_fill(&matr, *sq, &answ, sq_size) == 1)
			break ;
		delete_square(sq, sq_size);
		del_matrix(&matr);
		sq_size++;
	}
	del_matrix(&matr);
	return (sq_size);
}
*/
int main()
{
	t_dlist	*tet;
	t_figure	*f;
	t_dlist	*matr;
	char	**sq;

	f = ft_memalloc(sizeof(t_figure));
	f->n = 0;
	f->points = ft_memalloc(sizeof(t_point) * 4);
	f->points[0].i = 0;
	f->points[0].j = 0;
	f->points[1].i = 0;
	f->points[1].j = 1;
	f->points[2].i = 1;
	f->points[2].j = 0;
	f->points[3].i = 1;
	f->points[3].j = 1;
	tet = ft_dlst_create_elem(f);
	tet->content_size = 1;
	matr = create_matrix(4, tet, sq);
	pr(matr);
	return (0);
}
/*
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
*/
