# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:08:56 by ikoukou           #+#    #+#              #
#    Updated: 2022/03/13 04:37:03 by ikoukou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

CC = gcc

SERVER = server.c
CLIENT = client.c

OBJS = $(SERVER:.c=.o)
OBJC = $(CLIENT:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
server_client: $(OBJS) $(OBJC)
	$(CC) $(FLAGS) $(OBJS) -o server
	$(CC) $(FLAGS) $(OBJC) -o client
	@echo "\n====== client and server created successfully =====\n"

all : server_client

clean :
	$(RM) $(OBJS) $(OBJC)
	@echo "\n==================== OBJ files =====================\n"

fclean : clean
	$(RM) client server
	@echo "====== client and server removed successfully ======\n"
re : fclean all

.PHONY: all clean fclean re server_client
