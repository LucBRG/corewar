
#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"

# define REGISTRE(x)	battle->cur_process->registre[x]
# define PC				battle->cur_process->pc
# define ID				b->cur_process->bot->id
# define SETPC(n)		((PC + n) % MEM_SIZE)
# define MAX(a, b)		((a > b) ? a : b)
# define CARRY			battle->cur_process->carry
# define ISREG(x)		(x >= 0 && x < REG_NUMBER)

enum{NOTHING, LIVE, LD, ST, ADD, SUB, AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD,
	LLDI, LFORK, AFF};

typedef unsigned char	uc;
typedef struct s_battle	t_battle;
typedef int (*t_listfunc[3])(t_battle *b, int params[3], int *size);

typedef struct	s_bot
{
	int			id;
	int			live;
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
	int			dead;
	char		carry;
	t_bot		*bot;
}				t_process;

typedef struct	s_battle
{
	uc			memory[MEM_SIZE];
	uc			print_mem[MEM_SIZE];
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
t_list			*addprocess(t_list **list, t_bot *bot, int pc);
int				load_func(t_battle *battle);
int				check_ocp(char inst, char ocp);

void			debug(uc *s, int len);
void			displaybot(t_bot *bot);
void			hexa(uc *s, int len, int color);
void			displayprocess(t_list *elem);
void			print_memory(t_battle *b);

void			add(t_battle *battle, int *params);
void			aff(t_battle *battle, int *params);
void			and_ft(t_battle *battle, int *params);
void			fork_ft(t_battle *battle, int ind, int a, int b);
int				ld(t_battle *battle, int params[3], int size[3]);
void			ldi(t_battle *battle, int ind1, int ind2, int reg);
void			lld(t_battle *battle, int param, int reg, int a);
void			lldi(t_battle *battle, int ind1, int ind2, int reg);
void			lfork(t_battle *battle, int ind, int a, int b);
int				live(t_battle *battle, int params[3], int size[3]);
void			or_ft(t_battle *battle, int param1, int param2, int reg);
int				st(t_battle *battle, int params[3], int size[3]);
void			sti(t_battle *battle, int reg, int ind1, int ind2);
void			sub(t_battle *battle, int reg1, int reg2, int reg3);
void			xor_ft(t_battle *battle, int param1, int param2, int reg);
void			zjmp(t_battle *battle, int ind, int a, int b);

#endif
