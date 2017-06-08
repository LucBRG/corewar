/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:29 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/08 17:37:53 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	int			i;
	t_process	*win;
	t_battle	*b;

	i = -1;
	if (!(b = initbattle(ac, av)))
		return (0);
	printf("FIGHT\t%d\n", b->bots.nb);
	if (b->bots.nb)
	{
		ft_lstiter(b->process, displayprocess);
		win = battle_launch(b);
		if (win)
			printf("le joueur %d(%s) a gagne\n", win->bot->id, win->bot->name);
	}
	return (0);
}
