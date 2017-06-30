/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:13:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/28 19:04:58 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				lfork(t_battle *battle, int params[3], int size[3])
{
	ft_printf("nouveau pc = %d\n", params[0]);
	if (size)
		;
	addprocess(&battle->process, battle->cur_process->bot,
		SETPC(params[0]));
	FLAG = 0;
	return (1000);
}
