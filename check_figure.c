/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:45:47 by celva             #+#    #+#             */
/*   Updated: 2019/10/16 21:34:30 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_correct_figure(t_point *m_point)
{
	int c;

	c = 0;
	if (((ABS((m_point[0].i - m_point[1].i)) + ABS((m_point[0].j
		- m_point[1].j))) == 1 || (ABS((m_point[0].i - m_point[2].i)) +
		ABS((m_point[0].j - m_point[2].j))) == 1 || (ABS((m_point[0].i -
		m_point[3].i)) + ABS((m_point[0].j - m_point[3].j))) == 1))
		c++;
	if (((ABS((m_point[1].i - m_point[2].i)) +
		ABS((m_point[1].j - m_point[2].j))) == 1 || (ABS((m_point[1].i -
		m_point[3].i)) + ABS((m_point[1].j - m_point[3].j))) == 1))
		c++;
	if (((ABS((m_point[2].i - m_point[3].i)) +
		ABS((m_point[2].j - m_point[3].j))) == 1))
		c++;
	else
		return (-1);
	if (c < 3)
		return (-1);
	return (c);
}

t_point	*check_simbols(char *str, t_point *m_point)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[4 * i + j] != '#' && str[4 * i + j] != '.')
				return (NULL);
			if (str[4 * i + j] == '#')
			{
				m_point[c].i = i;
				m_point[c++].j = j;
			}
			j++;
		}
		i++;
	}
	if (c != 4)
		return (NULL);
	return (m_point);
}

int		check_figure(t_dlist **figures, char *str, size_t count)
{
	t_point	*m_point;
	int		i;
	int		j;
	int		c;

	m_point = (t_point*)ft_memalloc(sizeof(t_point) * 4);
	if ((m_point = check_simbols(str, m_point)) == NULL)
		return (-1);
	c = 0;
	i = m_point[0].i;
	j = m_point[0].j;
	while (c < 4)
	{
		m_point[c].i = m_point[c].i - i;
		m_point[c].j = m_point[c].j - j;
		c++;
	}
	if (is_correct_figure(m_point) != -1)
		push_tetriminos(figures, m_point, count);
	else
		return (-1);
	return (0);
}
