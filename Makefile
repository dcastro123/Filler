# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 18:24:41 by dcastro-          #+#    #+#              #
#    Updated: 2017/09/22 17:15:28 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CMP = gcc -Wall -Werror -Wextra -g

LIB = -L libft/ -lft

SRCS = srcs/main.c

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
