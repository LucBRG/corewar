/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:33:20 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 14:48:36 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			and_ft(t_battle *battle, int param1, int param2, int reg)
{
	if (reg >= 0 && reg < REG_NUMBER)
	{
		REGISTRE(reg) = param1 & param2;
		CARRY = CHANGE(CARRY);
	}
}
