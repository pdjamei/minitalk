/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:16:35 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/09 16:37:36 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define EFEWARG	1
# define EMUCHARG	2
# define EPID		3
# define EKILL		4
# define EMALLOC	5

void				print_error(int er);
int					ft_atoi(char *s, int *ret);
void				sig_usr(int n);
int					ft_send(int pid, char *s);
int					ok(int i, int o);
int					ft_strlen(char *s);
char				*ft_strdup(char *s);

#endif /* !CLIENT_H */
