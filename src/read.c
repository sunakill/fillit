/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:44:20 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:20:39 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static char			**tab_char_tetri(char **tab, char *buf)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < tetri_numb(buf))
	{
		tab[j] = (char*)malloc(sizeof(char) * 20 + 1);
		if (tab[j] == NULL)
			return (NULL);
		while (k < 20)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][20] = NUL;
		k = 0;
		j++;
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char				**check_tetri_file_tetri_tab(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = NUL;
	g_nb_tetrimino = tetri_numb(buf);
	tmp = (char**)malloc(sizeof(char *) * tetri_numb(buf) + 1);
	if (tmp == NULL)
		return (NULL);
	if (check_tetri_file(buf) == 0)
		return (NULL);
	tmp = tab_char_tetri(tmp, buf);
	return (tmp);
}

t_tetrimino			*char_tab_tetri_list_chained(char **tab)
{
	int			i;
	t_tetrimino	*start;
	t_tetrimino	*ptr;

	i = 1;
	start = NULL;
	ptr = NULL;
	start = switch_newtetri_to_letter(ft_strsplit(tab[0], ENDLINE), 0);
	ptr = start;
	while (i < g_nb_tetrimino)
	{
		ptr->next = switch_newtetri_to_letter(ft_strsplit(tab[i], ENDLINE), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (start);
}
