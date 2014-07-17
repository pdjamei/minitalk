/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:42:12 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/08 03:41:27 by fberot-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "client.h"

void		sig_usr(int n)
{
	if (n == SIGUSR1)
		ok(0, 2);
	else
		ok(1, 2);
	ok(1, 1);
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
}
