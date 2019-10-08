/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:02:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/07 14:02:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_dlist	*tet;
	char	**res;

	if (ac != 2)
	{
		ft_putendl("Error");
		return (0);
	}
	tet = read_tetriminos(av[1]);
	res = find_square(tet);
	return (0);
}
/*
int main(int ac, char **av)
{
	t_point *t;
	t_dlist *tet;
	t_dlist *matr;
	t_dlist *row;
	t_dlist *tmp;

	tet = read_tetriminos("in.txt");
	matr = create_matrix(2, tet);
	tmp = matr;
	
	while (tmp != NULL)
	{
		row = (t_dlist *)(tmp->content);
		while (row != NULL)
		{
			printf("%c", *((char*)(row->content)));
			row = row->next;
		}
		printf("\n");
		tmp = tmp->next;
	}
	//system("pause");
	return (0);
}
*/
