/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:42:26 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:20:02 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void			print_solution(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar(ENDLINE);
		i++;
	}
}

static int			floated_square_size(void)
{
	int		square_size;
	float	float_nb;

	float_nb = ft_sqrt((float)(g_nb_tetrimino) * 4.0);
	square_size = (int)float_nb;
	if (square_size == float_nb)
		return (square_size);
	return (square_size);
}

void				clean_tab(char **tab, int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

int					main(int argc, char **argv)
{
	t_tetrimino *start;
	char		**tab;

	start = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_usage();
		return (-1);
	}
	if ((tab = check_tetri_file_tetri_tab(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if (check_tetri_tab(tab) == 0)
	{
		ft_putendl("error");
		clean_tab(tab, g_nb_tetrimino + 1);
		return (-1);
	}
	start = char_tab_tetri_list_chained(tab);
	clean_tab(tab, g_nb_tetrimino + 1);
	print_solution(final_fillit_solution(start, floated_square_size(), NULL));
	return (0);
}
