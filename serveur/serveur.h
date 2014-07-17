/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberot-a <fberot-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:16:35 by fberot-a          #+#    #+#             */
/*   Updated: 2014/02/09 17:06:16 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# define EMALLOC	1
# define EMUCHARG	2
# define EKILL		3
# define EFILE		4
# define BARG		5

typedef struct		s_list
{
	int				pid;
	int				i;
	char			*str;
	char			c;
	char			crc;
	int				nbchar;
	int				flag;
	struct s_list	*next;
}					t_list;

void				ft_putnbr(int n, int fd);
int					ft_strlen(char *s);
int					ft_strcmp(char *s1, char *s2);
t_list				*list(t_list *li, int o);
t_list				*l_new(int pid, int bit);
int					l_add(int pid, int bit);
void				destroy(int pid);
int					logfile(int fd, int o);
int					error(int i);
void				print_error(int er);
void				print_disco(int pid);
int					modify(t_list *tmp, int bit);
void				ft_printlog(int pid, int sig, int flag);

#endif /* !SERVEUR_H */
