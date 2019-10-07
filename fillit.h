/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:19:25 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/07 18:07:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <io.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

/*
const char figure_1_1[] = "#...#...#...#...";
# define figure_1_2 "####............"
# define figure_2_1 ".##.##.........."
# define figure_2_2 "#...##...#......"
# define figure_3_1 "##...##........."
# define figure_3_2 ".#..##..#......."
# define figure_4_1 "##..##.........."
# define figure_5_1 "#...#...##......"
# define figure_5_2 "..#.###........."
# define figure_5_3 "##...#...#......"
# define figure_5_4 "###.#..........."
# define figure_6_1 "###..#.........."
const char figure_6_2[] = "#...##..#.......";
# define figure_6_3 ".#..###........."
# define figure_6_4 ".#..##...#......"
# define figure_7_1 ".#...#..##......"
# define figure_7_2 "#...###........."
# define figure_7_3 "##..#...#......."
# define figure_7_4 "###...#........."
# define f_transit_2_1 "##.##..........."
# define f_transit_3_2 "#..##..#........"
# define f_transit_5_2 "#.###..........."
# define f_transit_6_3 "#..###.........."
# define f_transit_6_4 "#..##...#......."
# define f_transit_7_1 "#...#..##......."
*/
typedef struct	s_point
{
	int				i;
	int				j;
}				t_point;
char		**create_square(size_t size);
void		del_col(t_dlist *lst, size_t col);
void		del_row(t_dlist **lst, size_t col);
void		del_square(t_dlist **lst);
#endif
