/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:21:41 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/20 17:52:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				fork_ft(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	FLAG = 0;
	if (!addprocess(&battle->process, cpyprocess(battle->cur_process,
		SETPC(params[0] % IDX_MOD))))
		return (0);
	return (1);
}
