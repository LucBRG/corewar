/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:43:13 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/01 16:56:43 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_battle.h"

void		sti(t_battle *battle, int reg, int ind1, int ind2)
{
		int ret;

		ret = ind1 + ind2;
		if ((battle->cur_men + ret) < MEM_SIZE)
			battle->cur_men += ret;
		else
			battle->cur_men += ret % MEM_SIZE - MEM_SIZE;
		battle->memory[battle->cur_men] = reg;
		return ;
}
