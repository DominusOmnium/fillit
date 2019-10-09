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
		res[i] = ft_memset(res[i], '.', size);
		i++;
	}
	return (res);
}

void	delete_square(char ***matrix, size_t size)
{
	while (--size >= 0)
		ft_memdel((void**)&(matrix[size]));
	ft_memdel((void**)matrix);
}
