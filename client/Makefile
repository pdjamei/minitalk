# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 23:27:59 by fberot-a          #+#    #+#              #
#    Updated: 2014/02/08 00:43:38 by fberot-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

CC = gcc

RM = rm -rf

SRCS = util.c\
	   signal.c\
	   client.c

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

