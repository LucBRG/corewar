
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
		// printf("%p\tlive : %d\tdead : %d\n", process, process->bot->live, process->dead);
		if (!process->dead)
		{
			total += process->bot->live;
			// displayprocess(elem);
			if (!process->bot->live && !process->dead)
			{
				//printf("mise a mort de %d(%s)\n", process->bot->id, process->bot->name);
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
	int		tmp;

	loop = 0;
	cycle = CYCLE_TO_DIE;
	while (42)
	{
		elem = battle->process;
		while (elem)
		{
			if (PROCESS->stun > 0)
				PROCESS->stun--;
			else if (!PROCESS->dead)
			{
				battle->cur_process = PROCESS;
				// hexa(battle->memory, MEM_SIZE, 0);
				// printf("\n\n");
				// print_memory(battle);
				tmp = load_func(battle);
				PC = SETPC(tmp);
				ft_printf("pc = %d\n", PC);
				ft_printf("stun = %d\n", PROCESS->stun);
				// ft_printf("i = %d\n", (PC + i) % MEM_SIZE);
			}
			elem = elem->next;
		}
		loop++;
		getchar();
		if (!rulescycle(battle, &loop, &cycle))
			return (battle->cur_process);
		if (loop == 100)
			return (NULL);
	}
	return (NULL);
}

t_battle	*initbattle(int ac, char **av)
{
	t_battle	*b;

	if (!(b = malloc(sizeof(t_battle))))
		return (NULL);
	b->bots = loadbots(ac, av);
	if (!(b->process = loadmemory(b)))
		return (NULL);
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
