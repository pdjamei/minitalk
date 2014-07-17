/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:27:51 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/08 06:25:13 by fberot-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "serveur.h"

int			ft_strlen(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

void		ft_putnbr(int n, int fd)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
