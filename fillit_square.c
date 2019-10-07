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
/*
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
}*/

char	**create_square(size_t size)
{
	char	**res;
	size_t	i;

	if ((res = (char**)ft_memalloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if ((res[i] = (char*)ft_memalloc(size)) == NULL)
		{
			while (--i >= 0)
				ft_memdel((void**)&(res[i]));
			ft_memdel((void**)&res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

void	delete_square(char **matrix, size_t size)
{
	while (--size >= 0)
		ft_memdel((void**)&(matrix[size]));
	ft_memdel((void**)matrix);
}
