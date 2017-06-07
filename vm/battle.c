/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:47:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/06 18:47:25 by tferrari         ###   ########.fr       */
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

void	load_func(t_battle *battle)
{
	int p1;
	int p2;
	int p3;

	if (INST != 1)
	{
		p1 = chartoint(&PARAMS, PARAM(0));
		p2 = chartoint(&PARAMS + PARAM(0), PARAM(1));
		p3 = chartoint(&PARAMS + PARAM(0) + PARAM(1), PARAM(2));
	}
	else
	{
		p1 = chartoint(&PARAMS, 4);
		p2 = 0;
		p3 = 0;
	}
	// printf("params\t: %X\t%d\t%d\t%d\n", INST, PARAM(0), PARAM(1), PARAM(2));
	if (INST > 0 && INST <= 16)
		battle->func[INST - 1](battle, p1, p2, p3);
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
				process->dead = 1;
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
				load_func(battle);
			}
			elem = elem->next;
		}
		if (!rulescycle(battle, &loop, &cycle))
			return (battle->cur_process);
		loop++;
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
