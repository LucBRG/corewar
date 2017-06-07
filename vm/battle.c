/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:47:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 14:15:48 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define INST		battle->memory[PC]
#define OCP			battle->memory[PC + 1]
#define PARAMS		battle->memory[PC + 2]
#define PARAM(n)	(OCP >> ((3 - n) * 2) & 0b11)

void	test(t_battle *b, int p1, int p2, int p3)
{
	// printf("id : %d\t params : %d %d %d\n", b->cur_process->bot->id, p1, p2, p3);
}

int		load_func(t_battle *battle)
{
	int pc;
	int params[3];
	int sizep[3];

	pc = PC;
	ft_bzero(params, sizeof(int) * 3);
	ft_bzero(sizep, sizeof(int) * 3);
	if (INST > 0 && INST <= 16)
	{
		if (INST == AFF)
			sizep[0] = T_REG;
		else if (INST == LIVE || INST == ZJMP || INST == FORK || INST == LFORK)
			sizep[0] = T_DIR;
		else
		{
			sizep[0] = PARAM(0);
			sizep[1] = PARAM(1);
			sizep[2] = PARAM(2);
		}
		params[0] = chartoint(&PARAMS, sizep[0]);
		params[1] = chartoint(&PARAMS + sizep[0], sizep[1]);
		params[2] = chartoint(&PARAMS + sizep[0] + sizep[1], sizep[2]);
		battle->func[INST - 1](battle, params[0], params[1], params[2]);
	}
	// printf("params\t: %d\t%d\t%d\t%d\n", INST, params[0], params[1], params[2]);
	// printf("sizep\t: %d\t%d\t%d\t%d\n", MAX((sizep[0] + sizep[1] + sizep[2]), 1), sizep[0], sizep[1], sizep[2]);
	return ((pc == PC) ? MAX((sizep[0] + sizep[1] + sizep[2]), 1) : 0);
}

int			verif_live(t_battle *battle)
{
	int			total;
	t_list		*elem;
	t_process	*process;

	total = 0;
	elem = battle->process;
	while (elem)
	{
		process = (t_process*)elem->content;
		if (!process->dead)
		{
			total += process->bot->live;
			if (!process->bot->live)
			{
				printf("mise a mort de %d(%s)\n", process->bot->id, process->bot->name);
				process->dead = 1;
			}
			else
				process->bot->live = 0;
		}
		elem = elem->next;
	}
	return (total);
}

int			rulescycle(t_battle *battle, int *loop, int *cycle)
{
	static int checks = 0;
	int live;

	if (*loop == *cycle)
	{
		if (!(live = verif_live(battle)))
			return (0);
		if (live >= NBR_LIVE)
			*cycle -= CYCLE_DELTA;
		if (checks >= MAX_CHECKS)
		{
			checks = 0;
			(*cycle)--;
		}
		*loop = 0;
		checks++;
	}
	return (1);
}

t_process	*battle_launch(t_battle *battle)
{
	int		loop;
	int		cycle;
	t_list	*elem;

	loop = 0;
	cycle = CYCLE_TO_DIE;
	while (42)
	{
		elem = battle->process;
		while (elem)
		{
			if (!((t_process*)elem->content)->dead)
			{
				battle->cur_process = (t_process*)elem->content;
				PC = (PC + load_func(battle)) % MEM_SIZE;
			}
			elem = elem->next;
		}
		if (!rulescycle(battle, &loop, &cycle))
			return (battle->cur_process);
		loop++;
		// return (NULL);// a supprimer
	}
	return (NULL);
}

t_battle	*initbattle(int ac, char **av)
{
	t_battle	*b;

	if (!(b = malloc(sizeof(t_battle))))
		return (NULL);
	b->bots = loadbots(ac, av);
	b->process = loadmemory(b);
	b->func[0] = test;
	b->func[1] = test;
	b->func[2] = test;
	b->func[3] = test;
	b->func[4] = test;
	b->func[5] = test;
	b->func[6] = test;
	b->func[7] = test;
	b->func[8] = test;
	b->func[9] = test;
	b->func[10] = test;
	b->func[11] = test;
	b->func[12] = test;
	b->func[13] = test;
	b->func[14] = test;
	b->func[15] = test;
	return (b);
}
