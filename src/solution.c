/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:46:19 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:37 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		check_tetri_pos(t_tetrimino *start, char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == DIESE && (start->x + j >= square_size
						|| start->y + i >= square_size))
				return (0);
			if (start->tetrimino[i][j] == DIESE && \
					ft_isalpha(tab[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static char		**if_check_tetri_pos_ok(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == DIESE)
				tab[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static char		**switch_letter_to_point(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != NUL)
		{
			if (tab[i][j] == start->letter)
				tab[i][j] = POINT_GRID;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int				best_pos_recursive(t_tetrimino *start, int square_size,
		char **tab)
{
	if (start != NULL)
	{
		while (start->y * start->x < square_size * square_size)
		{
			if ((check_tetri_pos(start, tab, square_size)) == 1)
			{
				tab = if_check_tetri_pos_ok(start, tab);
				if (best_pos_recursive(start->next, square_size, tab) == 1)
					return (1);
				tab = switch_letter_to_point(start, tab);
			}
			if (start->x < square_size)
				start->x++;
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}

char			**final_fillit_solution(t_tetrimino *start, int square_size,
		char **tab_solved)
{
	final_fix_tetri(start);
	tab_solved = char_tab_to_mem_to_solve(tab_solved, square_size);
	while (best_pos_recursive(start, square_size, tab_solved) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		clean_tab(tab_solved, square_size);
		tab_solved = char_tab_to_mem_to_solve(tab_solved, square_size);
	}
	return (tab_solved);
}
