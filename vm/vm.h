/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:19:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 16:35:07 by dbischof         ###   ########.fr       */
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

typedef unsigned char 	uc;
typedef struct s_battle	t_battle;
typedef void (*t_listfunc[16])(t_battle *b, int p1, int p2, int p3);

typedef struct	s_bot
{
	int			id;
	char		*name;
	char		*comment;
	uc			*instructions;
	int			nb_instructions;
}				t_bot;

typedef struct	s_bots
{
	int			nb;
	t_bot		*tab[4];
}				t_bots;

typedef struct	s_process
{
	int			registre[REG_NUMBER];
	int			pc;
	int			live;
	int			dead;
	char		carry;
	t_bot		*bot;
}				t_process;

typedef struct	s_battle
{
	uc			memory[MEM_SIZE];
	t_process	*cur_process;
	t_bots		bots;
	t_list		*process;
	t_listfunc	func;
}				t_battle;

int				open_bot(char *path, uc **bot);
t_bot			*creabot(char *path);
t_bots			loadbots(int ac, char **av);
t_list			*loadmemory(t_battle *b);
uc				*getmemory(t_battle *b, int index, uc *buff, int len);
int				setmemory(t_battle *b, int index, uc *s, int len);
t_process		newprocess(t_bot *bot, int pc);
int				chartoint(unsigned char *t, int len);
char			*inttochar(int *i);
int				mod(int a, int b);
t_battle		*initbattle(int ac, char **av);
t_process		*battle_launch(t_battle *battle);

void			debug(uc *s, int len);
void			displaybot(t_bot *bot);
void			hexa(uc *s, int len, int color);
void			displayprocess(t_list *elem);

void			sti(t_battle *battle, int reg, int ind1, int ind2);
void			and_ft(t_battle *battle, int param1, int param2, int *reg);
void			or_ft(t_battle *battle, int param1, int param2, int *reg);

#endif
