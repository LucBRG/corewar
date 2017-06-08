/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:13:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:32:14 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			lfork(t_battle *battle, int ind, int a, int b)
{
	a = b;
	addprocess(&battle->process, battle->cur_process->bot, SETPC(ind));
}
