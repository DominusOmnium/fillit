/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:02:52 by marvin            #+#    #+#             */
/*   Updated: 2019/10/10 13:32:40 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
/*
int		find_best_col(t_dlist *matr, size_t n)
{
	size_t	i;
	size_t	min;
	int		ind;
	int		*sums;

	if ((sums = (int*)ft_memalloc(n * sizeof(int))) == NULL)
		return (-1);
	while (matr != NULL)
	{
		i = -1;
		while (++i < n)
			if ((((t_row*)matr->content)->line)[i] == '1')
				sums[i]++;
	}
	i = -1;
	min = -1;
	ind = -1;
	while (++i < n)
		if (sums[i] != 0 && sums[i] < min)
		{
			min = sums[i];
			ind = i;
		}
	ft_memdel((void**)&sums);
	return (ind);
}
*/
void	remove_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ, int row)
{
	int		ind[4];
	size_t	i;
	size_t	j;
	t_dlist	*tmp;
	t_dlist	*tmp1;

	i = -1;
	j = 0;
	ft_dlst_push_front(answ, ft_dlst_popi(matr, row));
	while (++i < ((t_row*)(*answ)->content)->line_len)
		if ((((t_row*)((*answ)->content))->line)[i] == '1')
			ind[j++] = i;
	tmp = *matr;
	while (tmp != NULL)
	{
		if ((((t_row*)(tmp->content))->line)[ind[0]] == '1' ||
			(((t_row*)(tmp->content))->line)[ind[1]] == '1' ||
			(((t_row*)(tmp->content))->line)[ind[2]] == '1' ||
			(((t_row*)(tmp->content))->line)[ind[3]] == '1' ||
			((t_row*)(tmp->content))->n == ((t_row*)(*answ)->content)->n)
		{
			tmp1 = tmp->next;
			tmp = ft_dlst_pop(matr, tmp);
			ft_dlst_push_front(rm, tmp);
			tmp = tmp1;
		}
		else
			tmp = tmp->next;
	}
}

void	add_rows(t_dlist **matr, t_dlist **rm, t_dlist **answ)
{
	t_dlist	*tmp;
	
	tmp = ft_dlst_popi(answ, 0);
	ft_dlst_push_sort(matr, tmp, &fillit_dlst_cmp);
	while ((tmp = ft_dlst_popi(rm, 0)) != NULL)
		ft_dlst_push_sort(matr, tmp, &fillit_dlst_cmp);
}

int		is_correct_matr(t_dlist *matr, t_dlist *answ, size_t not)
{
	size_t	i;
	
	i = 1;
	while (i <= not)
	{
		while (matr != NULL)
		{
			if (((t_row*)(matr->content))->n == i)
				break;
			matr = matr->next;
		}
		if (matr == NULL)
			while (answ != NULL)
			{
				if (((t_row*)(answ->content))->n == i)
					break;
				answ = answ->next;
			}
		if (matr == NULL && answ == NULL)
			return (0);
		i++;
	}
	return (1);
}

int		can_fill(t_dlist **matr, t_dlist **answ, size_t not)
{
	size_t	col;
	t_dlist	*removed;
	t_dlist	*tmp;
	
	tmp = *matr;
	removed = NULL;
	if (is_correct_matr(tmp, *answ, not) == 1)
	{
		if (ft_dlst_len(tmp) == 0)
			return (1);
	}
	else
		return (0);
	while (tmp != NULL)
	{
		if (tmp != )
		remove_rows(matr, &removed, answ, ft_dlst_index_of(*matr, tmp));
		if (can_fill(matr, answ, not) == 1)
			break ;
		else
			add_rows(matr, &removed, answ);
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	else
		return (1);
}

size_t	find_square(char *fname, char ***sq)
{
	size_t	sq_size;
	t_dlist	*tet;
	t_dlist	*matr;
	t_dlist	*answ;

	t_point *points = ft_memalloc(sizeof(t_point) * 4);
	points[0].i = 0;
	points[0].j = 0;
	points[1].i = 1;
	points[1].j = 0;
	points[2].i = 1;
	points[2].j = 1;
	points[3].i = 1;
	points[3].j = 2;
	tet = ft_dlst_create_elem(points);
	tet->content_size = 3;
	points = ft_memalloc(sizeof(t_point) * 4);
	points[0].i = 0;
	points[0].j = 0;
	points[1].i = 0;
	points[1].j = 1;
	points[2].i = 1;
	points[2].j = 0;
	points[3].i = 1;
	points[3].j = 1;
	ft_dlst_push_front(&tet, ft_dlst_create_elem(points));
	tet->content_size = 2;
	points = ft_memalloc(sizeof(t_point) * 4);
	points[0].i = 0;
	points[0].j = 0;
	points[1].i = 0;
	points[1].j = 1;
	points[2].i = 1;
	points[2].j = 0;
	points[3].i = 1;
	points[3].j = 1;
	ft_dlst_push_front(&tet, ft_dlst_create_elem(points));
	tet->content_size = 1;
	/*points = ft_memalloc(sizeof(t_point) * 4);
	points[0].i = 0;
	points[0].j = 0;
	points[1].i = 0;
	points[1].j = 1;
	points[2].i = 0;
	points[2].j = 2;
	points[3].i = 1;
	points[3].j = 2;
	ft_dlst_push_front(&tet, ft_dlst_create_elem(points));
	tet->content_size = 1;*/
	sq_size = 1;
	if (sq_size == 0)
		return (0);
	while (1)
	{
		*sq = create_square(sq_size);
		matr = create_matrix(sq_size, tet);
		pr(matr);
		answ = NULL;
		if (can_fill(&matr, &answ, 3) == 1)
			break ;
		sq_size++;
	}
	printf("END\n");
	pr(answ);
	printf("END\n");
	return (sq_size);
}

int main(int ac, char **av)
{
	t_dlist	*tet;
	t_dlist	*matr;
	char	**sq;
	int res;

	t_figure *f = ft_memalloc(sizeof(t_figure));
	f->n = 0;
	f->points = ft_memalloc(sizeof(t_point) * 4);
	f->points[0].i = 0;
	f->points[0].j = 0;
	f->points[1].i = 0;
	f->points[1].j = 1;
	f->points[2].i = 1;
	f->points[2].j = 0;
	f->points[3].i = 1;
	f->points[3].j = 1;
	tet = ft_dlst_create_elem(f);
	tet->content_size = 1;
	res = find_square(av[1], &sq);
	//pr(matr);
	//res = find_square(av[1], &sq);
	return (0);
}

/*
int		main(int ac, char **av)
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
*/
/*
int main()
{
	t_dlist	*matr;
	t_dlist	*matr1;
	t_dlist	*tet;

	matr1 = NULL;
	t_figure *f = ft_memalloc(sizeof(t_figure));
	f->n = 2;
	f->points = ft_memalloc(sizeof(t_point) * 4);
	f->points[0].i = 0;
	f->points[0].j = 0;
	f->points[1].i = 1;
	f->points[1].j = 0;
	f->points[2].i = 1;
	f->points[2].j = 1;
	f->points[3].i = 1;
	f->points[3].j = 2;
	tet = ft_dlst_create_elem(f);
	tet->content_size = 1;
	f = ft_memalloc(sizeof(t_figure));
	f->n = 1;
	f->points = ft_memalloc(sizeof(t_point) * 4);
	f->points[0].i = 0;
	f->points[0].j = 0;
	f->points[1].i = 0;
	f->points[1].j = 1;
	f->points[2].i = 1;
	f->points[2].j = 0;
	f->points[3].i = 1;
	f->points[3].j = 1;
	ft_dlst_push_front(&tet, ft_dlst_create_elem(f));
	tet->content_size = 1;
	matr = create_matrix(4, tet);
	pr(matr);
	printf("////////////\n");
	ft_dlst_push_front(&matr1, ft_dlst_popi(&matr, 0));
	ft_dlst_push_front(&matr1, ft_dlst_popi(&matr, 1));
	ft_dlst_push_front(&matr1, ft_dlst_popi(&matr, 4));
	ft_dlst_push_front(&matr1, ft_dlst_popi(&matr, 7));
	pr(matr1);
	printf("////////////\n");
	pr(matr);
	printf("////////////\n");
	ft_dlst_push_sort(&matr, ft_dlst_popi(&matr1, 0), &fillit_dlst_cmp);
	ft_dlst_push_sort(&matr, ft_dlst_popi(&matr1, 0), &fillit_dlst_cmp);
	ft_dlst_push_sort(&matr, ft_dlst_popi(&matr1, 0), &fillit_dlst_cmp);
	ft_dlst_push_sort(&matr, ft_dlst_popi(&matr1, 0), &fillit_dlst_cmp);
	pr(matr);
	return (0);
}
*/
