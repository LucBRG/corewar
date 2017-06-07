/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 15:37:08 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		sti(t_battle *battle, int reg, int ind1, int ind2)
{
		int ret;
		uc *str;

		ret = ind1 + ind2;
		reg = REGISTRE(reg);
		str = (uc *)inttochar(&reg);
		setmemory(battle, (PC + ret) % MEM_SIZE, str, 4);
}
