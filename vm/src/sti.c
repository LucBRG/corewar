/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/28 17:58:08 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			sti(t_battle *battle, int params[3], int size[3])
{
	uc	*str;
	int	i;

	i = -1;
	// ft_printf("reg 1 = %d\n", REGISTRE(params[0]));
	while (++i < 3)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
		else if (size[i] == T_REG)
			params[i] = REGISTRE(params[i]);
	str = (uc*)inttochar(&params[0]);
	setmemory(battle, SETPC(params[1] + params[2]), str, sizeof(int));
	FLAG = 0;
	return (25);
}
