/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 14:47:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			lldi(t_battle *battle, int ind1, int ind2, int reg)
{
	int	ret;
	uc	str[4];

	ret = ind1 + ind2;
	REGISTRE(reg) = chartoint(getmemory(battle,
	(PC + ret) % MEM_SIZE, str, 4), 4);
	CARRY = CHANGE(CARRY);
}
