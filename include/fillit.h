/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regradul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:51:18 by regradul          #+#    #+#             */
/*   Updated: 2017/12/06 03:27:12 by regradul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../src/libft/libft.h"

int			g_nb_tetrimino;
# define BUFF_SIZE 4096

# define DIESE ('#')
# define POINT_GRID ('.')
# define ENDLINE ('\n')
# define NUL ('\0')

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

t_tetrimino				*final_fix_tetri(t_tetrimino *start);
int						check_tetri_tab(char **tab);
int						tetri_numb(char *s);
char					**check_tetri_file_tetri_tab(char *argv);
t_tetrimino				*char_tab_tetri_list_chained(char **tab);
t_tetrimino				*switch_newtetri_to_letter(char **tetrimino, int num);
char					**final_fillit_solution(t_tetrimino *start,
		int square_size, char **tab_solved);
char					**char_tab_to_mem_to_solve(char **tab, int square_size);
void					clean_tab(char **tab, int tab_size);
int						check_square(char *s);
int						check_bar(char *s);
int						check_height_line(char *s);
int						check_width_col(char *s);
int						check_diese_nearbtwthem(char *s);
int						check_void_btw_scndandthrd_diese(char *s);
int						check_tetri_file(char *buf);
int						ft_sqrt(int nb);
void					ft_usage(void);

#endif
