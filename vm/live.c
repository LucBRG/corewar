/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:33:06 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 15:44:47 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			live(t_battle *battle, int id, int a, int b)
{
	int i;

	i = -1;
	a = b;
	while (++i < battle->bots.nb)
		if (battle->bots.tab[i]->id == id)
			battle->bots.tab[id - 1]->live++;
}
