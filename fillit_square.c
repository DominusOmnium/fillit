/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:56:57 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 19:56:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dlist	*create_square(size_t size)
{
	size_t	i;
	size_t	j;
	t_dlist	*res;
	t_dlist	*dlst_str;

	i = 0;
	res = NULL;
	while (i < size)
	{
		j = 0;
		dlst_str = NULL;
		while (j < size)
		{
			ft_dlst_push_front(&dlst_str, ft_dlst_create_elemc(".", 1));
			j++;
		}
		ft_dlst_push_front(&res, ft_dlst_create_elem(dlst_str));
		i++;
	}
	return (res);
}

void	del_col(t_dlist *lst, size_t col)
{
	while (lst != NULL)
		ft_dlst_deli((t_dlist**)(&(lst->content)), col);
}

void	del_row(t_dlist *lst, size_t col)
{
	ft_dlst_deli((t_dlist**)(&(lst->content)), col);
}

void	del_square(t_dlist **lst)
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
