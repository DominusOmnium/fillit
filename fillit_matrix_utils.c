/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_matrix_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:05:06 by marvin            #+#    #+#             */
/*   Updated: 2019/10/17 13:19:15 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_line(t_point *tetr, t_point pos, char *str, size_t n)
{
	int		i;

	i = n * n - 1;
	while (i >= 0)
	{
		if ((tetr[0].i + pos.i) * n + (tetr[0].j + pos.j) == i ||
			(tetr[1].i + pos.i) * n + (tetr[1].j + pos.j) == i ||
			(tetr[2].i + pos.i) * n + (tetr[2].j + pos.j) == i ||
			(tetr[3].i + pos.i) * n + (tetr[3].j + pos.j) == i)
			str[i] = '1';
		else
			str[i] = '0';
		i--;
	}
}

int		add_row(t_dlist **matr, t_point pos, t_dlist *tetr, size_t n)
{
	t_row	*row;
	t_dlist	*tmp;

	if ((row = ft_memalloc(sizeof(t_row))) == NULL ||
		(row->line = ft_strnew(n * n)) == NULL ||
		(tmp = ft_dlst_create_elem((void*)row)) == NULL)
	{
		if (row != NULL)
			ft_memdel((void**)&(row->line));
		ft_memdel((void**)row);
		return (0);
	}
	row->n = tetr->content_size;
	row->line_len = n * n;
	fill_line((t_point*)(tetr->content), pos, row->line, n);
	ft_dlst_push_back(matr, tmp);
	if (tmp->prev == NULL)
		tmp->content_size = 0;
	if (tmp-> prev != NULL)
		tmp->content_size = tmp->prev->content_size + 1;
	return (1);
}

void	delete_matrix(t_dlist **lst)
{
	t_dlist *tmp;

	write(1, "1\n", 2);
	tmp = *lst;
	while (tmp != NULL)
	{
		ft_memdel((void**)&(((t_row*)(tmp->content))->line));
		ft_memdel(&(tmp->content));
		tmp = tmp->next;
	}
	write(1, "2\n", 2);
	ft_dlst_delete(lst);
}
