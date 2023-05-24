# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 15:39:10 by diosanto          #+#    #+#              #
#    Updated: 2023/05/17 15:46:56 by ribs             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address
RM		= rm -f

SRCS 	=	pipex.c					\
			error_handling.c		\
			UTILS/ft_split.c		\
			UTILS/ft_strncmp.c		\
			UTILS/triple_strjoin.c	\
			pipex_utils.c

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