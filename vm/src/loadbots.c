/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadbots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:14:51 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/26 11:30:34 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_bots	loadbots(int ac, char **av)
{
	int		i;
	t_bot	*tmp;
	t_bots	bots;

	i = 0;
	bots.nb = 0;
	while (++i < ac && bots.nb < MAX_PLAYERS)
	{
		if (av[i][0] != '-' && (tmp = creabot(av[i])))
		{
			bots.tab[bots.nb] = tmp;
			bots.tab[bots.nb]->id = -i;
			bots.tab[bots.nb]->rid = bots.nb;
			bots.nb++;
		}
	}
	return (bots);
}
