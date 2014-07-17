# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 23:27:59 by fberot-a          #+#    #+#              #
#    Updated: 2014/02/07 23:55:01 by fberot-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	make -C client
	make -C serveur

clean:
	make -C client clean
	make -C serveur clean

fclean: 
	make -C client fclean
	make -C serveur fclean

re: fclean all

.PHONY: all clean fclean re

