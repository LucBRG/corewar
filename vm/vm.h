/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:19:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/01 16:36:07 by tferrari         ###   ########.fr       */
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

typedef char[REG_SIZE] 	nb;

typedef struct		s_bot
{
	int				id;
	char			*name;
	char			*comment;
	unsigned char	*instructions;
	int				nb_instructions;
}					t_bot;

typedef struct		s_bots
{
	int				nb;
	t_bot			*tab[4];
}					t_bots;

typedef struct		s_process
{
	unsigned char	registre[REG_NUMBER][REG_SIZE];
	char			*pc;
	char			carry;
	t_bot			*bot;
}					t_process;

typedef struct		s_battle
{
	char			memory[MEM_SIZE];
	t_process		*cur_process;
	t_bots			bots;
	t_list			*process;
}					t_battle;

int		open_bot(char *path, unsigned char **bot);
t_bot	*creabot(char *path);
t_bots	loadbots(int ac, char **av);
int		loadmemory(t_battle *b);
char	*getmemory(t_battle *b, int index, char *buff, int len);
int		setmemory(t_battle *b, int index, char *s, int len);

void	debug(unsigned char *s, int len);
void	displaybot(t_bot *bot);

void	sti(t_battle *battle, int reg, int ind1, int ind2);
void	and_ft(t_battle *battle, int param1, int param2, int *reg);
void	or_ft(t_battle *battle, int param1, int param2, int *reg);

#endif
