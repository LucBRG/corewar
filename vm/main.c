/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/07 11:50:06 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int ac, char **av)
{
	int		i;
	t_battle *b;

	i = -1;
	b = initbattle(ac, av);
	// hexa(b->memory, MEM_SIZE, 0);
	printf("\n");
	ft_lstiter(b->process, displayprocess);
	hexa(b->memory, MEM_SIZE, 0);
	b->cur_process = b->process->content;
	lldi(b, 1, 0, 10);
	printf("\nregistre 10 : %x\n", b->cur_process->registre[10]);
	// b->cur_process->registre[10] = 100;
	printf("\nid gagnant\t: %d\n", battle_launch(b)->bot->id);
	printf("\nmodulo %d\n", b->cur_process->registre[10] % 256);
	aff(b, 10, 0 ,0);
	return (0);
}
