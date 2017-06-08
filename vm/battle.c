/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:18:33 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 14:28:23 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
		// printf("%p\tlive : %d\tdead : %d\n", process, process->bot->live, process->dead);
		if (!process->dead)
		{
			total += process->bot->live;
			if (!process->bot->live && !process->dead)
			{
				printf("mise a mort de %d(%s)\n", process->bot->id, process->bot->name);
				process->dead = 1;
			}
			process->bot->live = 0;
		}
		elem = elem->next;
	}
	return (total);
}

int			rulescycle(t_battle *battle, int *loop, int *cycle)
{
	static int	checks = 0;
	int			live;

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
				// hexa(battle->memory, MEM_SIZE, 0);
				// printf("\n\n");
				PC = SETPC(load_func(battle));
			}
			// displayprocess(elem);
			elem = elem->next;
		}
		if (!rulescycle(battle, &loop, &cycle))
			return (battle->cur_process);
		loop++;
		// if (loop ==2)
		// return (NULL);//a suppr
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
	b->func[0] = live;
	b->func[1] = ld;
	b->func[2] = st;
	b->func[3] = add;
	b->func[4] = sub;
	b->func[5] = and_ft;
	b->func[6] = or_ft;
	b->func[7] = xor_ft;
	b->func[8] = zjmp;
	b->func[9] = ldi;
	b->func[10] = sti;
	b->func[11] = fork_ft;
	b->func[12] = lld;
	b->func[13] = lldi;
	b->func[14] = lfork;
	b->func[15] = aff;
	return (b);
}
