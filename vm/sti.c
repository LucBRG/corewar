/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:45:55 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		sti(t_battle *battle, int reg, int ind1, int ind2)
{
	uc *str;

	if (ISREG(reg))
	{
		reg = REGISTRE(reg);
		str = (uc*)inttochar(&reg);
		setmemory(battle, SETPC(ind1 + ind2), str, sizeof(int));
	}
}
