/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:34:18 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/09 17:08:05 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "client.h"

int			ft_strlen(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

void		print_error(int er)
{
	write(2, "client: ", 8);
	if (er == EFEWARG)
	{
		write(2, "Missing arguments.\n", 19);
		write(2, "Usage: client pid message\n", 26);
	}
	else if (er == EMUCHARG)
	{
		write(2, "Too many arguments.\n", 20);
		write(2, "Usage: client pid message\n", 26);
	}
	else if (er == EPID)
	{
		write(2, "Invalid pid.\n", 13);
	}
	else if (er == EKILL)
		write(2, "Serveur closed\n", 15);
}

int			ft_atoi(char *s, int *ret)
{
	int		flag;

	*ret = 0;
	while (*s >= '0' && *s <= '9')
		*ret = *ret * 10 + (*(s++) - '0');
	flag = (*s ? -1 : 0);
	return (flag);
}

char		*ft_strdup(char *s)
{
	int		len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(s) + 1;
	len = (len % 8 == 0 ? len : len + 8 - (len % 8));
	if ((ret = (char *)malloc(len * sizeof(char))) == NULL)
		return (ret);
	tmp = ret;
	while ((*tmp = *s))
	{
		tmp++;
		s++;
		len--;
	}
	while (len--)
		*(tmp++) = '\0';
	return (ret);
}
