# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 17:55:35 by dcastro-          #+#    #+#              #
#    Updated: 2017/08/26 15:44:17 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CMP  = gcc -Wall -Werror -Wextra -c

LIBFT =	ft_atoi.c ft_bzero.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c\
	   	ft_isprint.c ft_memalloc.c ft_memccpy.c\
	   	ft_memchr.c ft_memcmp.c ft_memcpy.c\
	   	ft_memdel.c ft_memmove.c ft_memset.c\
	   	ft_putchar.c ft_putchar_fd.c ft_putendl.c\
	   	ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
	   	ft_putstr.c ft_putstr_fd.c ft_strcat.c\
	   	ft_strchr.c ft_strclr.c ft_strcmp.c\
	   	ft_strcpy.c ft_strdel.c ft_strdup.c\
		ft_strequ.c ft_striter.c ft_striteri.c\
	   	ft_strjoin.c ft_strlcat.c ft_strlen.c\
	   	ft_strmap.c ft_strmapi.c ft_strncat.c\
	   	ft_strncmp.c ft_strncpy.c ft_strnequ.c\
		ft_strnew.c ft_strnstr.c ft_strstr.c\
	   	ft_strsub.c ft_strtrim.c ft_tolower.c\
	   	ft_toupper.c ft_strrchr.c ft_strsplit.c\
	   	ft_itoa.c ft_spacecheck.c ft_wdcount.c\
	   	ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	   	ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	   	ft_wdlen.c ft_range.c ft_list_size.c\
	   	ft_itoa_base.c ft_uitoa.c get_next_line.c\
	   	ft_ultoa_base.c ft_uitoa_capbase.c ft_uitoa_base.c\
	   	ft_printf.c start_printf.c handle_str.c handle_int.c\
	   	handle_more_int.c arg_check.c format_out.c format_int.c

OBJS = 	ft_printf.o start_printf.o handle_str.o handle_int.o handle_more_int.o\
		arg_check.o\
		ft_uitoa_base.o ft_itoa_base.o ft_ultoa_base.o format_out.o format_int.o\
		ft_atoi.o ft_bzero.o ft_isalnum.o\
		ft_isalpha.o ft_isascii.o ft_isdigit.o\
	   	ft_isprint.o ft_memalloc.o ft_memccpy.o\
	   	ft_memchr.o ft_memcmp.o ft_memcpy.o\
	   	ft_memdel.o ft_memmove.o ft_memset.o\
	   	ft_putchar.o ft_putchar_fd.o ft_putendl.o\
	   	ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o\
	   	ft_putstr.o ft_putstr_fd.o ft_strcat.o\
	   	ft_strchr.o ft_strclr.o ft_strcmp.o\
	   	ft_strcpy.o ft_strdel.o ft_strdup.o\
		ft_strequ.o ft_striter.o ft_striteri.o\
	   	ft_strjoin.o ft_strlcat.o ft_strlen.o\
	   	ft_strmap.o ft_strmapi.o ft_strncat.o\
	   	ft_strncmp.o ft_strncpy.o ft_strnequ.o\
		ft_strnew.o ft_strnstr.o ft_strstr.o\
	   	ft_strsub.o ft_strtrim.o ft_tolower.o\
	   	ft_toupper.o ft_strrchr.o ft_strsplit.o\
	   	ft_itoa.o ft_spacecheck.o ft_wdcount.o\
	   	ft_lstnew.o ft_lstdelone.o ft_lstdel.o\
	   	ft_lstadd.o ft_lstiter.o ft_lstmap.o\
	   	ft_wdlen.o ft_range.o ft_list_size.o\
	   	ft_uitoa.o ft_uitoa_capbase.o get_next_line.o\

CMPSRCS = $(LIBFT)
INCL = -I includes/libft.h -I includes/ft_printf.h

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all : $(NAME)

$(NAME) : 
	@$(CMP) $(CMPSRCS) $(INCL)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean : 
	@/bin/rm -rf $(OBJS)

fclean : clean
	@/bin/rm -rf $(NAME)

re : fclean all

