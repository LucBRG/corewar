/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:05:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/31 14:54:13 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int ac, char **av)
{
	int		i;
	t_bots	bots;

	i = -1;
	bots = loadbots(ac, av);
	printf("nb bots: %d\n", bots.nb);
	while (++i < bots.nb)
		displaybot(bots.bots[i]);
	return (0);
}
