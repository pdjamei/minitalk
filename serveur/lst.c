/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:22:55 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/08 06:25:03 by fberot-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "serveur.h"

t_list		*list(t_list *li, int o)
{
	static t_list	*l = NULL;

	if (o == 1)
		l = li;
	return (l);
}

t_list		*l_new(int pid, int bit)
{
	t_list	*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (ret);
	if ((ret->str = (char *)malloc(sizeof(char))) == NULL)
	{
		free(ret);
		return (NULL);
	}
	*(ret->str) = '\0';
	ret->next = NULL;
	ret->i = 1;
	ret->flag = 0;
	ret->crc = 0;
	ret->nbchar = 0;
	ret->c = (char)bit;
	ret->pid = pid;
	return (ret);
}

int			l_add(int pid, int bit)
{
	t_list	*tmp;

	tmp = list(NULL, 0);
	if (tmp == NULL)
	{
		if (list(l_new(pid, bit), 1) == NULL)
			return (-1);
		return (0);
	}
	if (tmp->pid == pid)
		return (modify(tmp, bit));
	while (tmp->next)
	{
		if (tmp->next->pid == pid)
			return (modify(tmp->next, bit));
		tmp = tmp->next;
	}
	if ((tmp->next = l_new(pid, bit)) == NULL)
		return (-1);
	return (0);
}

void		destroy(int pid)
{
	t_list	*tmp;
	t_list	*tobefree;

	tmp = list(NULL, 0);
	if (tmp->pid == pid)
	{
		list(tmp->next, 1);
		free(tmp->str);
		free(tmp);
	}
	while (tmp->next)
	{
		if (tmp->next->pid == pid)
		{
			tobefree = tmp->next;
			tmp->next = tmp->next->next;
			free(tobefree->str);
			free(tobefree);
			return ;
		}
		tmp = tmp->next;
	}
}
