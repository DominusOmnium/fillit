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

int		find_best_col(t_dlist *matr)
{
	
}

int		can_fill(t_dlist *matr, char **sq)
{

}

size_t	find_square(char *fname, char **sq)
{
	size_t	res;
	t_dlist	*tet;
	t_dlist	*matr;

	res = read_tetriminos(fname, &tet);
	if (res == 0)
		return (0);
	while (1)
	{
		sq = create_square(res);
		matr = create_matrix(res, tet, sq);
		if (can_fill(matr, sq) == 1)
			break ;
		delete_square(sq, res);
		del_matrix(&matr);
		res++;
	}
}

int main(int ac, char **av)
{
	char	**sq;
	size_t	res;
	size_t	i;
	size_t	j;

	if (ac != 2)
	{
		ft_putendl("Error");
		return (0);
	}
	if ((res = find_square(av[1], sq)) == 0)
	{
		ft_putendl("Error");
		return (0);
	}
	i = 0;
	while (i < res)
		ft_putendl(sq[i++]);	
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
