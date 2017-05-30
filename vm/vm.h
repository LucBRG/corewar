/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:19:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/30 18:23:49 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "op.h"

typedef struct	s_bot
{
	char		*name;
	char		*comment;
	char		*instructions;
	int			nb_instructions;
}				t_bot;

typedef struct	s_bots
{
	int			nb_bots;
	t_bot		bots[4];
}				t_bots;

int		open_bot(char *path, unsigned char **bot);
t_bot	*creabot(char *path);

void	debug(unsigned char *s, int len);
void	displaybot(t_bot *bot);

#endif
