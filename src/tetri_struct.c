/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:49:07 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 19:22:32 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			check_width_col(char *s)
{
	int i;
	int width;
	int line_void;

	i = 0;
	width = 0;
	line_void = 0;
	while (i < 4)
	{
		if (s[i] == DIESE || s[i + 5] == DIESE || s[i + 10] == DIESE ||
				s[i + 15] == DIESE)
		{
			width++;
			if (line_void > 0)
				return (0);
		}
		else if (width > 0)
			line_void++;
		i++;
	}
	return (width);
}

int			check_height_line(char *s)
{
	int i;
	int height;
	int line_void;

	i = 0;
	height = 0;
	line_void = 0;
	while (i < 19)
	{
		if (s[i] == DIESE || s[i + 1] == DIESE || s[i + 2] == DIESE ||\
				s[i + 3] == DIESE)
		{
			height++;
			if (line_void > 0)
				return (0);
		}
		else if (height > 0)
			line_void++;
		i = i + 5;
	}
	return (height);
}

int			check_void_btw_scndandthrd_diese(char *s)
{
	int i;
	int h;
	int bug;

	bug = 0;
	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		if (s[i] == DIESE)
			h++;
		if (h == 2 && s[i] == DIESE)
		{
			while (s[i + 1 + bug] != DIESE && s[i + bug] != '\0')
				bug++;
			if (bug > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int			check_diese_nearbtwthem(char *s)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == DIESE)
		{
			if (s[i + 1] == DIESE || s[i - 1] == DIESE || s[i + 5] == DIESE ||
					s[i - 5] == DIESE)
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
