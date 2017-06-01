/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:05:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/01 09:32:26 by dbischof         ###   ########.fr       */
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
	printf("%d\n", loadmemory(&b));
	return (0);
}
