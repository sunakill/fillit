# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regradul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 03:17:16 by regradul          #+#    #+#              #
#    Updated: 2017/12/06 18:53:23 by regradul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_tetri_file.c\
	  read.c\
	  tetri.c\
	  usage.c\
	  fix_tetri.c\
	  main.c\
	  solution.c\
	  tetri_struct.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =src/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
	make -C ./src/libft/

clean:
	rm -f $(OBJ)
	make clean -C ./src/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./src/libft/

re: fclean all

.PHONY : all, re, clean, flcean
