/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/21 18:36:00 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			sti(t_battle *battle, int params[3], int size[3])
{
	uc	*str;
	int	i;

	i = -1;
	while (++i < 3)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
		else if (size[i] == T_REG)
			params[i] = REGISTRE(params[i]);
	str = (uc*)inttochar(&params[0]);
	setmemory(battle, SETPC(params[1] + params[2]), str, sizeof(int));
	return (25);
}
