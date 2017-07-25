/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:21:41 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:33:29 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fork_ft(t_battle *battle, t_command *c)
{
	addprocess(&battle->process, cpyprocess(battle->cur_process,
		SETPC(c->params[0] % IDX_MOD)));
}
