
#include "vm.h"

#define PROCESS	((t_process*)elem->content)

int			verif_live(t_battle *battle)
{
	int			total;
	t_list		*elem;
	t_process	*process;

	total = 0;
	elem = battle->process;
	while (elem)
	{
		process = PROCESS;
		if (!process->dead)
		{
			total++;
			if (!process->live && !process->dead)
			{
				total--;
				process->bot->nbprocess--;
				process->dead = 1;
			}
			process->live = 0;
		}
		elem = elem->next;
	}
	return (total);
}

int			rulescycle(t_battle *battle)
{
	int			live;

	if (battle->fight.loop == battle->fight.limitloop)
	{
		if (!(live = verif_live(battle)))
			return (0);
		if (live >= NBR_LIVE)
			battle->fight.limitloop -= CYCLE_DELTA;
		if (battle->fight.cycle >= MAX_CHECKS)
		{
			battle->fight.cycle = 0;
			battle->fight.limitloop--;
		}
		battle->fight.loop = 0;
		battle->fight.cycle++;
	}
	return (1);
}

void	battle_launch(t_battle *battle)
{
	t_list		*elem;
	int			tmp;

	while (rulescycle(battle))
	{
		elem = battle->process;
		while (elem)
		{
			if (PROCESS->stun > 0)
				PROCESS->stun--;
			if (!PROCESS->dead && !PROCESS->stun)
			{
				battle->cur_process = PROCESS;
				tmp = load_func(battle);
				PC = SETPC(tmp);
			}
			elem = elem->next;
		}
		battle->fight.loop++;
		battle->fight.totalloop++;
		showallview(battle);
	}
	return ;
}

void		initbattle_func(t_battle *battle)
{
	battle->func[0] = live;
	battle->func[1] = ld;
	battle->func[2] = st;
	battle->func[3] = add;
	battle->func[4] = sub;
	battle->func[5] = and_ft;
	battle->func[6] = or_ft;
	battle->func[7] = xor_ft;
	battle->func[8] = zjmp;
	battle->func[9] = ldi;
	battle->func[10] = sti;
	battle->func[11] = fork_ft;
	battle->func[12] = lld;
	battle->func[13] = lldi;
	battle->func[14] = lfork;
	battle->func[15] = aff;
}

t_battle	*initbattle(int ac, char **av)
{
	t_battle	*b;

	if (!(b = malloc(sizeof(t_battle))))
		return (NULL);
	b->bots = loadbots(ac, av);
	if (!(b->process = loadmemory(b)))
		return (NULL);
	b->view = NULL;
	b->fight.loop = 0;
	b->fight.totalloop = 0;
	b->fight.cycle = 0;
	b->fight.limitloop = CYCLE_TO_DIE;
	b->fight.last_live = NULL;
	initbattle_func(b);
	return (b);
}
