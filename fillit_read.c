/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:58 by celva             #+#    #+#             */
/*   Updated: 2019/10/04 22:44:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	check_figure(t_dlist **figures, char *str)
{
	int i;
	int flag;
	int m;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '#' && flag == 0)
			m = i;
		if (str[i] == '#')
		{
			str[i - m] = '#';
			str[i] = '.';
		}
		i++;
	}
	if (ft_strcmp(str, figure_1_1) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_1_2) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, f_transit_2_1) == 0)
	{
		//как-то добавление в список как figure_2_1
		return (0);
	}
	if (ft_strcmp(str, figure_2_2) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_3_1) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, f_transit_3_2) == 0)
	{
		//как-то добавление в список как figure_3_2
		return (0);
	}
	if (ft_strcmp(str, figure_4_1) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_5_1) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, f_transit_5_2) == 0)
	{
		//как-то добавление в список как figure_5_2
		return (0);
	}
	if (ft_strcmp(str, figure_5_3) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_5_4) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_6_1) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_6_2) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, f_transit_6_3) == 0)
	{
		//как-то добавление в список как figure_6_3
		return (0);
	}
	if (ft_strcmp(str, f_transit_6_4) == 0)
	{
		//как-то добавление в список как figure_6_4
		return (0);
	}
	if (ft_strcmp(str, f_transit_7_1) == 0)
	{
		//как-то добавление в список как figure_7_1
		return (0);
	}
	if (ft_strcmp(str, figure_7_2) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_7_3) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	if (ft_strcmp(str, figure_7_4) == 0)
	{
		//как-то добавление в список
		return (0);
	}
	return (-1);
}

int	fillit_read(t_dlist **figures, char *fname)
{
	int		fd;
	int		i;
	char	*str;
	char	*new;
	
	str = (char*)malloc(sizeof(char) * 17);
	fd = open(fname, O_RDONLY);
	new = str;
	while (1)
	{
		i = 0;
		while (i < 4)
		{
			if (read(fd, str, 5) == 0)
				return (0);
			if (str[4] != '\n')
				return (-1);
			str += 4;
			i++;
		}
		if (check_figure(figures, str) == -1)
			return (-1);
		if (read(fd, str, 1) != 0 && *str != '\n')
			return (-1);
	}
}

/*int main()
{
	char *str = ".....#...##..#..";
	printf("%s\n", check_figure(str));
}*/
