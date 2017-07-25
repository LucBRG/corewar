
#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "op.h"
# include "view.h"

# define SETREGISTRE(x, v)	set_registre(battle->cur_process, x - 1, v)
# define GETREGISTRE(x)		get_registre(battle->cur_process, x - 1)
# define PC					battle->cur_process->pc
# define ID					battle->cur_process->bot->id
# define INST				battle->memory[PC]
# define MEMORY				battle->memory
# define SETPC(n)			((PC + n) % MEM_SIZE)
# define MAX(a, b)			((a > b) ? a : b)
# define CARRY				battle->cur_process->carry
# define ISREG(x)			(x > 0 && x <= REG_NUMBER)
# define ISOP(x)			(INST > x && INST <= x)
# define STUN				battle->cur_process->stun
# define FLAG				battle->cur_process->flag

enum{NOTHING, LIVE, LD, ST, ADD, SUB, AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD,
	LLDI, LFORK, AFF};

typedef struct s_view t_view;
typedef unsigned char	uc;
typedef struct s_battle	t_battle;
typedef int (*t_listfunc[16])(t_battle *b, int params[3], int *size);

typedef struct	s_bot
{
	int			id;
	int			rid;
	char		*name;
	char		*comment;
	uc			*instructions;
	int			nb_instructions;
	int			loop;
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
	int			stun;
	int			dead;
	int			live;
	char		carry;
	t_bot		*bot;
	int			id;
	int			flag;
	int			last_action[3];
}				t_process;

typedef struct	s_fight
{
	int			loop;
	int			limitloop;
	int			cycle;
	int			totalloop;
	t_bot		*last_live;
}				t_fight;

typedef struct	s_battle
{
	uc			memory[MEM_SIZE];
	uc			print_mem[MEM_SIZE];
	t_process	*cur_process;
	t_bots		bots;
	t_list		*process;
	t_listfunc	func;
	int			count;
	t_view		*view;
	t_fight		fight;
}				t_battle;

typedef struct	s_command
{
	uc			inst;
	uc			ocp;
	int			params[3];
	int			size[3];
	int			type[3];
	int			isocp;
	int			len;
	int			error;
}				t_command;

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
void			battle_launch(t_battle *battle);
t_list			*addprocess(t_list **list, t_process process);
t_process 		cpyprocess(t_process *orignal, int pc);
int				load_func(t_battle *battle);
int				check_ocp(char inst, char ocp);
int				stun(t_battle *battle, t_command *c);
void			set_registre(t_process *process, int i, int value);
int				get_registre(t_process *process, int i);

void			debug(uc *s, int len);
void			displaybot(t_bot *bot);
void			hexa(uc *s, int len, int color);
void			displayprocess(t_list *elem);
void			print_memory(t_battle *b);
char			*ft_strhexa(unsigned char *str, int len);
t_command		getcommand(t_battle *battle, int pc);

int				add(t_battle *battle, int params[3], int size[3]);
int				aff(t_battle *battle, int params[3], int size[3]);
int				and_ft(t_battle *battle, int params[3], int size[3]);
int				fork_ft(t_battle *battle, int params[3], int size[3]);
int				ld(t_battle *battle, int params[3], int size[3]);
int				ldi(t_battle *battle, int params[3], int size[3]);
int				lld(t_battle *battle, int params[3], int size[3]);
int				lldi(t_battle *battle, int params[3], int size[3]);
int				lfork(t_battle *battle, int params[3], int size[3]);
int				live(t_battle *battle, int params[3], int size[3]);
int				or_ft(t_battle *battle, int params[3], int size[3]);
int				st(t_battle *battle, int params[3], int size[3]);
int				sti(t_battle *battle, int params[3], int size[3]);
int				sub(t_battle *battle, int params[3], int size[3]);
int				xor_ft(t_battle *battle, int params[3], int size[3]);
int				zjmp(t_battle *battle, int params[3], int size[3]);

#endif
