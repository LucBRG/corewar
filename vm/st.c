/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 12:10:53 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:45:49 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			st(t_battle *battle, int reg, int param, int a)
{
	uc *str;

	a = 0;
	if (ISREG(reg))
	{
		reg = REGISTRE(reg);
		str = (uc*)inttochar(&reg);
		setmemory(battle, SETPC(param % IDX_MOD), str, sizeof(int));
	}
}
