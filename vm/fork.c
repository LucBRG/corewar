/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:21:41 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 15:28:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			fork_ft(t_battle *battle, int ind, int a, int b)
{
	addprocess(&battle->process, battle->cur_process->bot,
	(PC + (ind + a + b) % IDX_MOD) % MEM_SIZE);
}
