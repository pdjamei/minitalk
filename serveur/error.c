/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:21:48 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/09 16:40:26 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "serveur.h"

void			print_error(int er)
{
	write(2, "serveur: ", 9);
	if (er == EMUCHARG)
		write(2, "Too many arguments.\n", 20);
	else if (er == EMALLOC)
		write(2, "malloc() error.\n", 16);
	else if (er == EFILE)
		write(2, "Logfile error.\n", 15);
	else if (er == BARG)
		write(2, "Bad argument.\nUsage : serveur [-l]\n", 35);
}

int				error(int i)
{
	static int	er = 0;

	if (i)
		er = i;
	return (er);
}

void			print_disco(int pid)
{
	destroy(pid);
	ft_putnbr(pid, 1);
	write(1, " was disconnected.\n", 18);
}

void			ft_printlog(int pid, int sig, int flag)
{
	int			fd;

	fd = logfile(0, 0);
	if (flag == 0)
		write(fd, "<- ", 3);
	else
		write(fd, "-> ", 3);
	ft_putnbr(pid, fd);
	write(fd, " : ", 3);
	if (sig == SIGUSR1)
		write(fd, "SIGUSR1\n", 8);
	else
		write(fd, "SIGUSR2\n", 8);
}
