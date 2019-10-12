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

void	ft_dlst_pushsort(t_dlist **dl, t_dlist *el, int *f(t_dlist*, t_dlist*))
{
	t_dlist	*tmp;

	if (dl == NULL || el == NULL || f == NULL)
		return ;
	if (*dl == NULL)
	{
		*dl = el;
		el->prev = NULL;
		el->next = NULL;
		return ;
	}
	tmp = *dl;
	while (tmp->next != NULL)
	{
		if (f(el, tmp) == 1)
			break ;
		tmp = tmp->next;
	}
	el->next = tmp->next;
	el->prev = tmp;
	tmp->next = el;
}
