/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:05:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 12:12:50 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#define PC		battle->cur_process->pc
#define INST	battle->memory[PC]
#define OCP		battle->memory[PC + 1]
#define PARAMS	battle->memory[PC + 2]
#define PARAM(n)(OCP >> ((3 - n) * 2) & 0b11)

void	test(t_battle *b, int p1, int p2, int p3)
{
	printf("%d\t%d\t%d\t%d\n", b->cur_process->bot->id, p1, p2, p3);
}

void	load_func(t_battle *battle)
{
	static char value[3] = {T_REG, T_DIR, T_IND};
	int p1;
	int p2;
	int p3;

	OCP = 0x68;
	if (INST != 1)
	{
		p1 = chartoint(&PARAMS, PARAM(0));
		p2 = chartoint(&PARAMS + PARAM(0), PARAM(1));
		p3 = chartoint(&PARAMS + PARAM(0) + PARAM(1), PARAM(2));
	}
	printf("params\t: %X\t%d\t%d\t%d\n", INST, PARAM(0), PARAM(1), PARAM(2));
	battle->func[INST - 1](battle, p1, p2, p3);
}

void	battle_launch(t_battle *battle)
{
	t_list *elem;

	elem = battle->process;
	while (elem)
	{
		battle->cur_process = (t_process*)elem->content;
		load_func(battle);
		elem = elem->next;
	}
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

int			main(int ac, char **av)
{
	int		i;
	t_battle *b;

	i = 0x41424344;
	printf("%s\n", inttochar(&i));
	// b = initbattle(ac, av);
	// hexa(b->memory, MEM_SIZE, 0);
	// printf("\n");
	// ft_lstiter(b->process, displayprocess);
	// battle_launch(b);
	return (0);
}
