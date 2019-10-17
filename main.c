/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:22:41 by marvin            #+#    #+#             */
/*   Updated: 2019/10/17 14:30:10 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	**sq;
	int		res;

	if (ac != 2)
	{
		ft_putendl("error");
		return (0);
	}
	if ((res = find_square(av[1], &sq)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	print_square(sq, res);
	delete_square(&sq, res);
	return (0);
}
