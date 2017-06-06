/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:02:24 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 09:48:51 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process newprocess(t_bot *bot, int pc)
{
	t_process process;

	process.pc = pc;
	process.bot = bot;
	process.carry = 0;
	ft_bzero(process.registre, REG_NUMBER * REG_SIZE);
	process.registre[0] = bot->id;
	return (process);
}
