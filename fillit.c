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
	t_dlist	*tetriminos;

	tetriminos = read_tetriminos();
	return (0);
}

int main(int ac, char **av)
{
	t_dlist *sq;
	t_dlist	*tmp;
	t_dlist	*row;

	sq = create_square(5);
	tmp = sq;
	while (tmp != NULL)
	{
		row = (t_dlist *)(tmp->content);
		while (row != NULL)
		{
			printf("%c", *((char*)row->content));
			row = row->next;
		}
		printf("\n");
		tmp = tmp->next;
	}
	
	printf("-----------------------------------------------------------\n");
	
	del_col(sq, 0);
	tmp = sq;
	while (tmp != NULL)
	{
		row = (t_dlist *)(tmp->content);
		while (row != NULL)
		{
			printf("%c", *((char*)row->content));
			row = row->next;
		}
		printf("\n");
		tmp = tmp->next;
	}
	system("pause");
	return (0);
}
