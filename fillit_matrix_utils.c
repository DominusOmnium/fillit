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

int		add_row(t_dlist **matr, t_point pos, t_point *tetr, size_t n)
{
	int		i;
	char	*str;
	t_dlist	*tmp;

	i = n * n - 1;
	if (!(str = ft_strnew(n * n)) || !(tmp = ft_dlst_create_elem((void*)str)))
	{
		ft_memdel((void**)&str);
		return (0);
	}
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
	ft_dlst_push_back(matr, tmp);
	return (1);
}

void	del_row(t_dlist **lst, size_t row)
{
	ft_dlst_deli(lst, row);
}

void	del_matrix(t_dlist **lst)
{
	t_dlist *tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_memdel(&(tmp->content));
		tmp = tmp->next;
	}
	ft_dlst_delete(lst);
}
