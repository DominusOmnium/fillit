/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:44:26 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/05 13:45:44 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlst_create_elem(void *data)
{
	t_dlist	*res;
	
	if (data == NULL || (res = ft_memalloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	res->data = ft_memcpy(res->data, &data, 4);
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
