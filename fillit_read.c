/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/03 14:03:44 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_figure(t_dlist **figures, char *str)
{
}

int	fillit_read(t_dlist **figures, char *fname)
{
	int		fd;
	char	*str;
	char	*new;
	
	str = (char*)malloc(sizeof(char) * 17);
	fd = open(fname, O_RDONLY);
	new = str;
	while (read(fd, str, 5) != 0)
	{
		read(fd, str, 5);
		if (str[4] != '\n')
			return (-1);
		str += 4;
	}
}
