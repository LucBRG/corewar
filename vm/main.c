/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:05:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 18:42:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int ac, char **av)
{
	int		i;
	t_battle b;

	i = -1;
	b.bots = loadbots(ac, av);
	printf("nb bots: %d\n", b.bots.nb);
	while (++i < b.bots.nb)
		displaybot(b.bots.tab[i]);
	loadmemory(&b);
	b.cur_process = b.process->content;
	ft_printf("live = %d\n", b.bots.tab[0]->live);
	hexa((uc *)&b.cur_process->registre[10], 4, 0);
	return (0);
}
