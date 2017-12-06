/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:39:09 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:19:29 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static char			**fix_up(int i_min, char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i + i_min < 4)
	{
		tab[i] = tab[i + i_min];
		i++;
	}
	while (i < 4 && i_min > 0)
	{
		tab[i] = "....NUL";
		i++;
	}
	return (tab);
}

static char			**fix_left(int j_min, char **tab)
{
	int tmp;
	int i;
	int j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tab[i][j + j_min] != NUL)
		{
			tab[i][j] = tab[i][j + j_min];
			j++;
		}
		tmp = j_min;
		while (tmp > 0 && tmp > 0)
		{
			tab[i][4 - tmp] = ENDLINE;
			tmp--;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static int			find_y_min(char **tab)
{
	int x;
	int y;
	int y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (tab[x][y] != DIESE && tab[x][y] != NUL)
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

static int			find_x_min(char **tab)
{
	int x;
	int y;
	int x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (tab[x][y] != DIESE && tab[x][y] != NUL)
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

t_tetrimino			*final_fix_tetri(t_tetrimino *start)
{
	t_tetrimino *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->tetrimino = fix_left(find_x_min(tmp->tetrimino), tmp->tetrimino);
		tmp->tetrimino = fix_up(find_y_min(tmp->tetrimino), tmp->tetrimino);
		tmp = tmp->next;
	}
	return (start);
}
