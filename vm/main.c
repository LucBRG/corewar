/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/07 15:19:43 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int ac, char **av)
{
	int			i;
	t_process	*win;
	t_battle	*b;

	i = -1;
	b = initbattle(ac, av);
	ft_lstiter(b->process, displayprocess);
	printf("\nFIGHT\t%d\n\n", b->bots.nb);
	win = battle_launch(b);
	if (win)
		printf("le joueur %d(%s) a gagne\n", win->bot->id, win->bot->name);
	return (0);
}
