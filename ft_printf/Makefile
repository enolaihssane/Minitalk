# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikoukou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 01:32:25 by ikoukou           #+#    #+#              #
#    Updated: 2021/12/22 01:41:05 by ikoukou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c put.c put_hex.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c  libftprintf.h
	cc $(FLAGS) -c $<

$(NAME) : $(OBJS)
	ar -crs $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : fclean all clean re
