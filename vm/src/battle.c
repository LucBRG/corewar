
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
			total += process->live;
			// displayprocess(elem);
			if (!process->live && !process->dead)
			{
				//printf("mise a mort de %d(%s)\n", process->bot->id, process->bot->name);
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
	long long	dump;

	dump = -100;
	while (rulescycle(battle) && dump-- != 0) // Le_programme_peut_continuer && battle->dump-- != 0
	{
		elem = battle->process;
		// ft_printf("\n\n", PC);
		showallview(battle);
		while (elem)
		{
			// getch();
			if (PROCESS->stun > 0)
				PROCESS->stun--;
			else if (!PROCESS->dead)
			{
				// int j = 0;
				// if (ID == - 1)
				// 	while (++j <= 16)
				// 		ft_printf("reg %d = %x\n", j , REGISTRE(j));
				// ft_printf("\n");
				// ft_printf("Process not dead\n");
				battle->cur_process = PROCESS;
				// hexa(battle->memory, MEM_SIZE, 0);
				// printf("\n\n");
				// ft_printf("pc actuel = %d\n", PC);
				// print_memory(battle);
				// sleep(1);
				tmp = load_func(battle);
				// if (tmp) {
				// 	ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", tmp, PC, PC + tmp);
				// 	hexa(&INST, tmp, -1);
				// 	ft_printf("\n");
				// }
				// ft_printf("je fais avancer l'id %d de %d\n", PROCESS->id, tmp);
				PC = SETPC(tmp);
				// ft_printf("process id %d et stun %d tour et un ", PROCESS->id, PROCESS->stun);
				// ft_printf("pc = %d\n\n", PC);
				// ft_printf("stun = %d\n", PROCESS->stun);
				// ft_printf("i = %d\n", (PC + i) % MEM_SIZE);
			}
			// if (loop > 999)
			// print_memory(battle);
			// displayprocess(elem);
			// getchar();
			elem = elem->next;
		}
		battle->fight.loop++;
		battle->fight.totalloop++;
	}
	// ft_printf("loop = %d\n", loop);
	if (dump != -1)
		return ;
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
