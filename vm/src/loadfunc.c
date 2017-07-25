
#include "vm.h"

# define TYPEVAR(x)	((c->type[x] == REG_CODE) ? "r" : "")

// int		load_func(t_battle *battle)
// {
// 	int i;
// 	int pc;
// 	int params[3];
// 	int sizep[3];

// 	pc = PC;
// 	if ((INST > 0 && INST <= 16) && !((isocp(INST) && !check_ocp(INST, OCP))))
// 	{
// 		battle->count++;
// 		ft_bzero(params, sizeof(int) * 3);
// 		size_p(battle, &sizep);
// 		params_p(battle, &params, sizep);
// 		// ft_printf("inst\t: %d\n", INST);
// 		// ft_printf("params\t: %d\t%d\t%d\n", params[0], params[1], params[2]);
// 		// ft_printf("sizep\t: %d\t%d\t%d\n", sizep[0], sizep[1], sizep[2]);
// 		if (STUN == 0 && FLAG == 0)
// 			return (stun(battle));
// 		else if (STUN == 0 && FLAG == 1 && !(battle->func[INST - 1](battle, params, sizep)))
// 			return (1);
// 		// ft_printf("le stun = %d\n", battle->cur_process->stun);
// 		// ft_printf("pc = %d\n", pc);
// 		// ft_printf("passe\n");
// 		if (pc != PC)
// 			return (0);
// 	}
// 	else
// 		return (1);
// 	i = 1 + isocp(INST) + sizep[0] + sizep[1] + sizep[2];
// 	return (i);
// }

void	printfunc(t_battle *battle, t_command *c)
{
	const char	*instructions[17] = {"", "live", "ld", "st", "add", "sub",
		"and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi",
		"lfor", "aff"};
	int			i;

	i = -1;
	if (battle->opts.ncurses && battle->opts.verbose == 4)
	{
		mvprintw(battle->view->height, 1, "%40c", ' ');
		mvprintw(battle->view->height, 1, "p\t%d | %s", battle->cur_process->id,
			instructions[c->inst]);
		while (++i < 3)
			if (c->size[i])
				printw(" %s%d", TYPEVAR(i), c->params[i]);
		if (c->inst == ZJMP)
			printw(" %s", (CARRY) ? "OK" : "FAILED");
	}
	else if (battle->opts.verbose == 4)
	{
		ft_printf("p\t%d | %s", battle->cur_process->id, instructions[c->inst]);
		while (++i < 3)
			if (c->size[i])
				ft_printf(" %s%d", TYPEVAR(i), c->params[i]);
		if (c->inst == ZJMP)
			ft_printf(" %s", (CARRY) ? "OK" : "FAILED");
		ft_printf("\n");
	}
}

int		load_func(t_battle *battle)
{
	int pc;
	t_command command;

	pc = PC;
	command = getcommand(battle, pc);
	if (!command.error)
	{
		battle->count++;
		// ft_printf("inst\t: %d\n", INST);
		// ft_printf("params\t: %d\t%d\t%d\n", params[0], params[1], params[2]);
		// ft_printf("sizep\t: %d\t%d\t%d\n", sizep[0], sizep[1], sizep[2]);
		if (FLAG == 0)
			return (stun(battle, &command));
		FLAG = 0;
		printfunc(battle, &command);
		battle->func[INST - 1](battle, &command);
		// ft_printf("le stun = %d\n", battle->cur_process->stun);
		// ft_printf("pc = %d\n", pc);
		// ft_printf("passe\n");
	}
	if (command.inst == ZJMP && CARRY)
		return (0);
	return (command.len);
}
