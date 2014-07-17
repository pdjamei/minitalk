/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:05:06 by pdjamei           #+#    #+#             */
/*   Updated: 2014/02/09 17:06:00 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include "serveur.h"

char					*ft_realloc(char *s, char c, int len)
{
	char				*tmp;
	char				*ret;

	if (!(tmp = (char *)malloc((len + 2) * sizeof(char))))
		return (tmp);
	ret = tmp;
	while (len--)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = c;
	*(++tmp) = '\0';
	return (ret);
}

int						ft_putcheck(t_list *tmp)
{
	char				*stmp;

	tmp->flag = 1;
	if ((stmp = ft_realloc(tmp->str, tmp->c, tmp->nbchar)) == NULL)
		return (-1);
	free(tmp->str);
	tmp->nbchar++;
	tmp->str = stmp;
	tmp->crc ^= tmp->c;
	return (0);
}

int						ft_check(t_list *tmp)
{
	if (tmp->c == tmp->crc)
	{
		if (tmp->str[tmp->nbchar - 1] == '\0')
		{
			ft_putnbr(tmp->pid, 1);
			write(1, " : \"", 4);
			write(1, tmp->str, ft_strlen(tmp->str));
			write(1, "\"\n", 2);
			destroy(tmp->pid);
		}
		tmp->c = 0;
		tmp->i = 0;
		return (-2);
	}
	else
	{
		tmp->nbchar = (tmp->nbchar % 8 == 0 ?
				tmp->nbchar - 8 : tmp->nbchar - (tmp->nbchar % 8));
		tmp->str[tmp->nbchar + 1] = '\0';
	}
	tmp->crc = 0;
	return (0);
}

int						modify(t_list *tmp, int bit)
{
	tmp->c |= (bit << tmp->i);
	if (tmp->i != 7)
		tmp->i++;
	else
	{
		if (tmp->flag && tmp->nbchar % 8 == 0)
		{
			tmp->flag = 0;
			if (ft_check(tmp) == -2)
				return (-2);
		}
		else
			if (ft_putcheck(tmp) == -1)
				return (-1);
		tmp->c = 0;
		tmp->i = 0;
	}
	return (0);
}
