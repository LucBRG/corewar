/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:43:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:59:13 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

void			ldi(t_battle *battle, int ind1, int ind2, int reg)
{
	uc	str[SIZE];

	if (ISREG(reg))
	{
		getmemory(battle, SETPC((ind1 + ind2) % IDX_MOD), str, SIZE);
		REGISTRE(reg) = chartoint(str, SIZE);
	}
}
