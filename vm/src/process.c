/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:02:24 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/20 18:15:06 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process newprocess(t_bot *bot, int pc)
{
	t_process process;

	process.pc = pc;
	process.bot = bot;
	process.stun = 0;
	process.dead = 0;
	process.live = 0;
	process.carry = 0;
	ft_bzero(process.registre, REG_NUMBER * REG_SIZE);
	process.registre[0] = bot->id;
	process.flag = 0;
	process.last_action[0] = -1;
	process.last_action[1] = -1;
	// ft_printf("add process id = %d, pc = %d\n", process.id, process.pc);
	return (process);
}

t_process cpyprocess(t_process *orignal, int pc)
{
	t_process process;

	process.pc = pc;
	process.bot = orignal->bot;
	process.stun = 0;
	process.dead = 0;
	process.live = 0;
	process.carry = 0;
	ft_memcpy(process.registre, orignal->registre, REG_NUMBER * REG_SIZE);
	process.flag = 0;
	// ft_printf("add process id = %d, pc = %d\n", process.id, process.pc);
	return (process);
}
