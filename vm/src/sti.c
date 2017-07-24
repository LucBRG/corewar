/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/24 11:53:19 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			sti(t_battle *battle, int params[3], int size[3])
{
	uc	*str;
	int	i;

	i = -1;
	// ft_printf("reg 1 = %d\n", REGISTRE(params[0]));
	// if (params[0] == 6 && ID == -1)
	// 	ft_printf("sti reg %d, val reg = %d\n",params[0], REGISTRE(params[0]));
	while (++i < 3)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
		else if (size[i] == T_REG)
			params[i] = GETREGISTRE(params[i]);
	str = (uc*)inttochar(&params[0]);
	setmemory(battle, SETPC(params[1] + params[2]), str, sizeof(int));
	FLAG = 0;
	return (1);
}
