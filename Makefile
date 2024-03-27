# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 12:48:46 by databey           #+#    #+#              #
#    Updated: 2024/03/27 14:36:58 by databey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	server
SERVER_SRC		=	server.c utils.c 


CLIENT			=	client
CLIENT_SRC		=	client.c utils.c 

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra

SERVER_OBJS = $(SERVER_SRC:%.c=%.o)
CLIENT_OBJS = $(CLIENT_SRC:%.c=%.o)

all : $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_SRC) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_SRC) -o $(CLIENT)

clean :
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re 
