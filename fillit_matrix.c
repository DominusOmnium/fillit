/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:05:06 by marvin            #+#    #+#             */
/*   Updated: 2019/10/17 14:10:11 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_be_placed(size_t sq_s, t_point *tetr, t_point pos)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		if (pos.i + tetr[i].i >= sq_s || pos.i + tetr[i].i < 0 ||
			pos.j + tetr[i].j >= sq_s || pos.j + tetr[i].j < 0)
			return (0);
		i++;
	}
	return (1);
}

int		tetr_pos(t_dlist **matr, size_t sq_size, t_dlist *tetr)
{
	size_t	i;
	size_t	j;
	t_point	pos;

	i = 0;
	while (i < sq_size)
	{
		j = 0;
		while (j < sq_size)
		{
			pos.i = i;
			pos.j = j;
			if (can_be_placed(sq_size, (t_point*)(tetr->content), pos) == 1)
				if (add_row(matr, pos, tetr, sq_size) == 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	pr(t_dlist *matr)
{
	t_dlist *tmp;

	tmp = matr;
	if (tmp == NULL)
		ft_putendl("(null)");
	while (tmp != NULL)
	{
		ft_putnbr(tmp->content_size);
		ft_putstr(" - ");
		ft_putnbr(((t_row*)tmp->content)->n);
		ft_putstr(":\t");
		ft_putendl(((t_row*)(tmp->content))->line);
		tmp = tmp->next;
	}
}

t_dlist	*create_matrix(size_t sq_size, t_dlist *tetr)
{
	t_dlist	*matr;
	t_dlist	*tmp;
	size_t	n;

	matr = NULL;
	while (tetr != NULL)
	{
		if (tetr_pos(&matr, sq_size, tetr) == 0)
			return (NULL);
		tetr = tetr->next;
	}
	return (matr);
}

int		fillit_dlst_cmp(t_dlist *dl1, t_dlist *dl2)
{
	if (dl1->content_size > dl2->content_size)
		return (1);
	return (0);
}
