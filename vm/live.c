/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:33:06 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/06 18:41:16 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			live(t_battle *battle, int id, int a, int b)
{
	id += a + b;
	if (battle->bots.nb >= id && id > 0)
		battle->bots.tab[id - 1]->live++;
}
