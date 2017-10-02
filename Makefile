# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 18:24:41 by dcastro-          #+#    #+#              #
#    Updated: 2017/10/01 05:43:45 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CMP = gcc -Wall -Werror -Wextra -g

LIB = -L libft/ -lft

SRCS = srcs/main.c srcs/parse.c srcs/utils.c srcs/check.c srcs/place.c

INC = $(LIB) -I includes/filler.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CMP) $(INC) $(OBJ) -o $(NAME)

clean :
	make -C libft/ clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all
