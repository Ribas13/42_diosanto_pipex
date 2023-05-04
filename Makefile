# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 15:39:10 by diosanto          #+#    #+#              #
#    Updated: 2023/05/04 19:35:14 by diosanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address
RM		= rm -f

SRCS 	=	pipex.c

OBJS	= $(SRCS:c=o)

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM)  $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:  fclean $(NAME)

.PHONY: all clean fclean re