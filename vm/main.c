/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 18:46:33 by tferrari         ###   ########.fr       */
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
