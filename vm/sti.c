/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/06 15:32:14 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_battle.h"

void		sti(t_battle *battle, int reg, int ind1, int ind2)
{
		int ret;
		uc *str;

		ret = ind1 + ind2;
		reg = REGISTRE(reg);
		str = ft_inttochar((char*)&reg);
		setmemory(battle, ret, str, 4);
		// if ((battle->cur_process->pc + ret) < MEM_SIZE)
		// 	battle->cur_process->pc += ret;
		// else
		// 	battle->cur_men += ret % MEM_SIZE - MEM_SIZE;
		// battle->memory[battle->cur_process->pc] = reg;
		return ;
}
