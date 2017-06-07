/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:13:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 15:14:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			lfork(t_battle *battle, int ind, int a, int b)
{
	a = b;
	addprocess(&battle->process, battle->cur_process->bot,
	(PC + ind) % MEM_SIZE);
}
