/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:13:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:33:44 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lfork(t_battle *battle, t_command *c)
{
	// ft_printf("nouveau pc = %d\n", params[0]);
	addprocess(&battle->process, cpyprocess(battle->cur_process,
		SETPC(c->params[0])));
}
