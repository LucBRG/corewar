/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:55:26 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

void			lldi(t_battle *battle, int ind1, int ind2, int reg)
{
	uc	str[SIZE];

	if ((CARRY = ISREG(reg)))
	{
		getmemory(battle, SETPC(ind1 + ind2), str, SIZE);
		REGISTRE(reg) = chartoint(str, SIZE);
	}
}
