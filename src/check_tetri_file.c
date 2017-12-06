/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:36:08 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:18:29 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		check_char_numb(char *s)
{
	int i;
	int diese;
	int point_grid;
	int endline;

	i = 0;
	diese = 0;
	point_grid = 0;
	endline = 0;
	while (s[i] != NUL)
	{
		if (s[i] == DIESE)
			diese++;
		if (s[i] == POINT_GRID)
			point_grid++;
		if (s[i] == ENDLINE)
			endline++;
		if (s[i] != DIESE && s[i] != POINT_GRID && s[i] != ENDLINE)
			return (0);
		i++;
	}
	if (diese != 4 || point_grid != 12 || endline != 4)
		return (0);
	return (1);
}

static int		check_symbnl_in_line(char *s)
{
	int x;
	int y;
	int add_5;

	x = 0;
	y = 0;
	add_5 = 4;
	while (s[x] != NUL)
	{
		if (s[x] == POINT_GRID || s[x] == DIESE)
			y++;
		if (y > 4)
			return (0);
		if (s[x] == ENDLINE && x == add_5)
		{
			y = 0;
			add_5 += 5;
		}
		x++;
	}
	return (1);
}

static int		check_tetri_form(char *s)
{
	int i;
	int height;
	int width;

	i = 0;
	height = check_height_line(s);
	width = check_width_col(s);
	if (check_diese_nearbtwthem(s) == 0)
		return (0);
	if (check_void_btw_scndandthrd_diese(s) == 0 || width == 0 || height == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 1 && width == 4)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}

int				check_tetri_tab(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetrimino)
	{
		if (check_char_numb(tab[i]) != 1)
			return (0);
		if (check_symbnl_in_line(tab[i]) != 1)
			return (0);
		if (check_tetri_form(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int				check_tetri_file(char *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buf[x] != NUL)
	{
		if (buf[x] == ENDLINE)
			y++;
		if (y == 4)
		{
			if (buf[x + 1] != ENDLINE && buf[x + 1] != NUL)
				return (0);
			if (buf[x + 1] == ENDLINE)
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
