/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:02:24 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 16:35:35 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process newprocess(t_bot *bot, int pc)
{
	t_process process;

	process.pc = pc;
	process.bot = bot;
	process.live = 0;
	process.dead = 0;
	process.carry = 0;
	ft_bzero(process.registre, REG_NUMBER * REG_SIZE);
	process.registre[0] = bot->id;
	return (process);
}
