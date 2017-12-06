/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:48:05 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:22:01 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int					tetri_numb(char *s)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != NUL)
	{
		if (s[i] == ENDLINE && (s[i + 1] == ENDLINE || s[i + 1] == NUL))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

t_tetrimino			*switch_newtetri_to_letter(char **tetrimino, int num)
{
	t_tetrimino *new;

	new = NULL;
	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (new == NULL)
		return (NULL);
	new->tetrimino = tetrimino;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char				**char_tab_to_mem_to_solve(char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab = ft_memalloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tab[j][i++] = POINT_GRID;
		}
		tab[j][i] = NUL;
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
