/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:05:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 17:13:41 by dbischof         ###   ########.fr       */
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
	printf("id gagnant\t: %d\n", battle_launch(b)->bot->id);
	return (0);
}
