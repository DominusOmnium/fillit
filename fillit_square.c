/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:56:57 by marvin            #+#    #+#             */
/*   Updated: 2019/10/09 14:47:05 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_answers_to_square(char ***sq, t_dlist *answ, size_t size)
{
	char	fill;
	int		i;

	fill = 'A';
	while (answ->next != NULL)
		answ = answ->next;
	while (answ != NULL)
	{
		i = 0;
		while (i < size * size)
		{
			if ((((t_row*)(answ->content))->line)[i] == '1')
				(*sq)[i / size][i % size] = fill;
			i++;
		}
		fill++;
		answ = answ->prev;
	}
}

char	**create_square(size_t size, t_dlist *answ)
{
	char	**res;
	size_t	i;
	char	fill;

	if ((res = (char**)ft_memalloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if ((res[i] = (char*)ft_strnew(size)) == NULL)
		{
			while (--i >= 0)
				ft_memdel((void**)&(res[i]));
			ft_memdel((void**)&res);
			return (NULL);
		}
		res[i] = ft_memset(res[i], '.', size);
		i++;
	}
	add_answers_to_square(&res, answ, size);
	return (res);
}

void	print_square(char **sq, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putendl(sq[i]);
		i++;
	}
}

void	delete_square(char ***matrix, size_t size)
{
	while (--size >= 0)
		ft_memdel((void**)&(matrix[size]));
	ft_memdel((void**)matrix);
}
