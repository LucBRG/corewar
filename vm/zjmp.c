/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:17:28 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 14:47:35 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			zjmp(t_battle *battle, int ind, int a, int b)
{
	ind += a + b;
	if (battle->cur_process->carry == 1)
		battle->cur_process->pc = (battle->cur_process->pc + ind) % MEM_SIZE;
}
