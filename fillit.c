/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:02:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/17 17:29:00 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		is_removing(int ind[4], t_dlist *tmp, t_dlist *answ)
{
	if ((((t_row*)(tmp->content))->line)[ind[0]] == '1' ||
		(((t_row*)(tmp->content))->line)[ind[1]] == '1' ||
		(((t_row*)(tmp->content))->line)[ind[2]] == '1' ||
		(((t_row*)(tmp->content))->line)[ind[3]] == '1' ||
		((t_row*)(tmp->content))->n == ((t_row*)answ->content)->n)
		return (1);
	return (0);
}

void	remove_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ, t_dlist *row)
{
	int		ind[4];
	int		i;
	int		j;
	t_dlist	*tmp;
	t_dlist	*tmp1;

	i = -1;
	j = 0;
	ft_dlst_push_front(answ, ft_dlst_pop(matr, row));
	while (++i < ((t_row*)(row->content))->line_len)
		if ((((t_row*)((row->content)))->line)[i] == '1')
			ind[j++] = i;
	tmp = *matr;
	while (tmp != NULL)
	{
		if (is_removing(ind, tmp, *answ) == 1)
		{
			tmp1 = tmp->next;
			tmp = ft_dlst_pop(matr, tmp);
			ft_dlst_push_front(rm, tmp);
			tmp = tmp1;
		}
		else
			tmp = tmp->next;
	}
}

void	add_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ)
{
	t_dlist	*tmp;

	tmp = ft_dlst_popi(answ, 0);
	ft_dlst_push_sort(matr, tmp, &fillit_dlst_cmp);
	while ((tmp = ft_dlst_popi(rm, 0)) != NULL)
		ft_dlst_push_sort(matr, tmp, &fillit_dlst_cmp);
}

int		can_fill(t_dlist **matr, t_dlist **answ, size_t not)
{
	t_dlist	*removed;
	t_dlist	*tmp;

	tmp = *matr;
	removed = NULL;
	if (is_correct_matr(tmp, *answ, not) != 1)
		return (0);
	if (ft_dlst_len(tmp) == 0)
		return (1);
	while (tmp != NULL)
	{
		if (tmp && tmp->prev &&
			((t_row*)tmp->content)->n != ((t_row*)tmp->prev->content)->n)
			break ;
		remove_rows(matr, &removed, answ, tmp);
		if (can_fill(matr, answ, not) == 1)
		{
			delete_matrix(&removed);
			delete_matrix(matr);
			return (1);
		}
		add_rows(matr, &removed, answ);
		tmp = tmp->next;
	}
	return (0);
}

size_t	find_square(char *fname, char ***sq)
{
	size_t	not;
	size_t	sq_size;
	t_dlist	*tet;
	t_dlist	*matr;
	t_dlist	*answ;

	if ((not = read_tetriminos(fname, &tet)) == 0)
		return (0);
	sq_size = calc_square_size(not);
	while (1)
	{
		answ = NULL;
		if ((matr = create_matrix(sq_size, tet)) != NULL)
			if (can_fill(&matr, &answ, not) == 1)
				break ;
		delete_matrix(&matr);
		delete_matrix(&answ);
		sq_size++;
	}
	delete_matrix(&matr);
	if ((*sq = create_square(sq_size, answ)) == NULL)
		sq_size = 0;
	ft_dlst_delete(&tet);
	delete_matrix(&answ);
	return (sq_size);
}
