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
