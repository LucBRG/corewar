/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:03:45 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/06 17:05:31 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			xor_ft(t_battle *battle, int param1, int param2, int reg)
{
	if (reg >= 0 && reg < REG_NUMBER)
		REGISTRE(reg) = param1 ^ param2;
}
