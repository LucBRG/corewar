/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:56:28 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/06 17:56:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// int main(int ac, char **av)
// {
// 	int		i;
// 	t_battle b;

// 	i = -1;
// 	sti(battle, )
// 	b.bots = loadbots(ac, av);
// 	printf("nb bots: %d\n", b.bots.nb);
// 	while (++i < b.bots.nb)
// 		displaybot(b.bots.tab[i]);
// 	printf("%d\n", loadmemory(&b));
// }

int			main(int ac, char **av)
{
	int		i;
	t_battle *b;

	i = -1;
<<<<<<< HEAD
	b.bots = loadbots(ac, av);
	printf("nb bots: %d\n", b.bots.nb);
	while (++i < b.bots.nb)
		displaybot(b.bots.tab[i]);
	loadmemory(&b);
	b.cur_process = b.process->content;
	// b->cur_process->registre[10] = 200;
	// sti(&b, 10, 0, 50);
	xor_ft(&b, 0xFFFF00FF, 0xFF0000FF, 10);
	// ft_printf("reg 10 = %s\n", (char *)&b.cur_process->registre[10]);
	hexa((uc *)&b.cur_process->registre[10], 4, 0);
=======
	b = initbattle(ac, av);
	// hexa(b->memory, MEM_SIZE, 0);
	printf("\n");
	ft_lstiter(b->process, displayprocess);
	printf("id gagnant\t: %d\n", battle_launch(b)->bot->id);
>>>>>>> 9311dc61c0f5722408269ff1e5ac712bc3305a9a
	return (0);
}
