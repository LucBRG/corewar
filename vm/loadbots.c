/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadbots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:14:51 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/31 14:59:25 by dbischof         ###   ########.fr       */
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
	while (++i < ac && bots.nb < 4)
	{
		if ((tmp = creabot(av[i])))
		{
			bots.bots[bots.nb] = tmp;
			bots.nb++;
		}
	}
	return (bots);
}
