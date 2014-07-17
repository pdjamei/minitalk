/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:19:49 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/09 17:07:19 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include "serveur.h"

void					ft_ignore(int sig)
{
	if (sig == SIGUSR1)
		signal(SIGUSR2, SIG_IGN);
	else
		signal(SIGUSR1, SIG_IGN);
}

void					sig_usr(int sig, siginfo_t *info, void *context)
{
	int					i;
	struct sigaction	sigact;

	(void)context;
	if (info->si_pid != 0)
	{
		ft_ignore(sig);
		ft_printlog(info->si_pid, sig, 0);
		i = (sig == SIGUSR1 ? 1 : 0);
		if ((i = l_add(info->si_pid, i)) == -1)
		{
			error(EMALLOC);
			return ;
		}
		i = (i == -2 ? SIGUSR2 : SIGUSR1);
		ft_printlog(info->si_pid, i, 1);
		if (kill(info->si_pid, i) == -1)
			print_disco(info->si_pid);
	}
	sigact.sa_sigaction = &sig_usr;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
}

void					serveur(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &sig_usr;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	while (error(0) == 0)
		pause();
}

int						logfile(int filed, int o)
{
	static int			fd = -1;

	if (o == 1)
		fd = filed;
	return (fd);
}

int						main(int ac, char **av)
{
	if (ac > 2)
		print_error(EMUCHARG);
	else
	{
		if (ac == 2)
		{
			if (ft_strcmp("-l", av[1]) != 0)
			{
				print_error(BARG);
				return (0);
			}
			else
				if (logfile(open("serveur.log", O_WRONLY | O_APPEND | O_CREAT,
								00644), 1) == -1)
					print_error(EFILE);
		}
		write(1, "PID : ", 6);
		ft_putnbr(getpid(), 1);
		write(1, "\n", 1);
		serveur();
		print_error(error(0));
		if (logfile(0, 0) != -1)
			close(logfile(0, 0));
	}
	return (0);
}
