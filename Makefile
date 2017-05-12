# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/05/12 08:23:21 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in
LIB				= libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRCS			= srcs/main.c \
				  srcs/parse.c \
				  srcs/add_room.c \
				  srcs/links_to_tab.c \
				  srcs/get_links.c \
				  srcs/bfs.c \
				  srcs/put_ants.c \
				  srcs/parse_nodes.c

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

display:
	@echo " / \   / \   / \   / \   / \   / \ "
	@echo "( l ) ( e ) ( m ) ( - ) ( i ) ( n )"
	@echo " \_/   \_/   \_/   \_/   \_/   \_/ "

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): display $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft
	@echo "EXECUTABLE BUILT\t\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@/bin/rm -rf $(OBJS)
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
