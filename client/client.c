/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:19:49 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/09 16:37:04 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "client.h"

int			ok(int i, int o)
{
	static int	p = 0;
	static int	crc = 0;

	if (o == 1)
		p = i;
	if (o == 2 || o == 4)
		crc = i;
	if (o == 3 || o == 4)
		return (crc);
	return (p);
}

int			ft_pause(void)
{
	usleep(420);
	return (ok(0, 0));
}

int			sendbyte(int pid, char c)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < 8)
	{
		tmp = (((c >> i) & 1) == 1 ? SIGUSR1 : SIGUSR2);
		ok(0, 1);
		if (kill(pid, tmp) == -1)
			return (EKILL);
		if (ft_pause())
			i++;
	}
	return (0);
}

int			ft_send(int pid, char *s)
{
	int		i;
	char	crc;

	i = 0;
	while (1)
	{
		crc = (i % 8 == 0 ? s[i] : crc ^ s[i]);
		if (sendbyte(pid, s[i]) == EKILL)
			return (EKILL);
		if (i % 8 == 7)
		{
			if (sendbyte(pid, crc) == EKILL)
				return (EKILL);
			if (ok(3, 3) == 0)
				i -= (i % 8) + 1;
			else if (s[i] == '\0')
				return (0);
		}
		i++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		pid;
	int		ret;
	char	*tmp;

	if (ac > 3)
		print_error(EMUCHARG);
	else if (ac < 3)
		print_error(EFEWARG);
	else
		if (ft_atoi(av[1], &pid) == -1)
			print_error(EPID);
		else
		{
			signal(SIGUSR2, sig_usr);
			signal(SIGUSR1, sig_usr);
			if ((tmp = ft_strdup(av[2])) == NULL)
			{
				print_error(EMALLOC);
				return (0);
			}
			if ((ret = ft_send(pid, tmp)))
				print_error(ret);
			free(tmp);
		}
	return (0);
}
