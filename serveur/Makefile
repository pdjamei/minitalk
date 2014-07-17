# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 23:27:59 by fberot-a          #+#    #+#              #
#    Updated: 2014/02/09 17:06:29 by pdjamei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serveur

CC = gcc

RM = rm -rf

SRCS = util.c\
	   error.c\
	   lst.c\
	   modify.c\
	   serveur.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all %.o clean fclean re

