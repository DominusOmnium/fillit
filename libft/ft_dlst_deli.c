/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_deli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:25:15 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/05 13:04:20 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlst_deli(t_dlist **dlst, size_t i)
{
	t_dlist	*tmp;

	if (dlst == NULL)
		return (-1);
	while (i > 0)
	{
		if ((*dlst)->next == NULL)
			return (0);
		*dlst = (*dlst)->next;
	}
	if (i == 0)
	{
		tmp = (*dlst)->next;
		tmp->prev = NULL;
		ft_memdel((void **)&((*dlst)->content));
		ft_memdel((void **)dlst);
		*dlst = tmp;
	}
	else
	{
		(*dlst)->prev->next = (*dlst)->next;
		(*dlst)->next->prev = (*dlst)->prev;
		ft_memdel((void **)&((*dlst)->content));
		ft_memdel((void **)dlst);
	}
	return (1);
}
