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

void	add_row(t_dlist **matr, t_point pos, t_point *tetr, size_t n)
{
	int	i;
	t_dlist	*dlst_str;

	i = n * n - 1;
	dlst_str = NULL;
	while (i >= 0)
	{
		if ((tetr[0].i + pos.i) * n + (tetr[0].j + pos.j) == i ||
			(tetr[1].i + pos.i) * n + (tetr[1].j + pos.j) == i ||
			(tetr[2].i + pos.i) * n + (tetr[2].j + pos.j) == i ||
			(tetr[3].i + pos.i) * n + (tetr[3].j + pos.j) == i)
			ft_dlst_push_front(&dlst_str, ft_dlst_create_elemc("1", 1));
		else
			ft_dlst_push_front(&dlst_str, ft_dlst_create_elemc("0", 1));
		i--;
	}
	ft_dlst_push_back(matr, ft_dlst_create_elem((void*)dlst_str));
}

void	del_col(t_dlist *lst, size_t col)
{
	while (lst != NULL)
	{
		ft_dlst_deli((t_dlist**)(&(lst->content)), col);
		lst = lst->next;
	}
}

void	del_row(t_dlist **lst, size_t col)
{
	ft_dlst_deli(lst, col);
}

void	del_matrix(t_dlist **lst)
{
	t_dlist *tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_dlst_delete((t_dlist **)(&(tmp->content)));
		tmp = tmp->next;
	}
	ft_dlst_delete(lst);
}
