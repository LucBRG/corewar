/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:33:06 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/14 21:55:17 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			live(t_battle *battle, int params[3], int size[3])
{
	int i;

	i = -1;
	if (size[3] != T_IND)
		return (0);
	while (++i < battle->bots.nb)
		if (battle->bots.tab[i]->id == params[0])
			battle->bots.tab[i]->live++;
	return (1);
}
