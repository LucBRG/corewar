/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:14:27 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/24 11:52:50 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				or_ft(t_battle *battle, int params[3], int size[3])
{
	int i;

	i = -1;
	while (++i < 2)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
		else if (size[i] == 1)
			params[i] = GETREGISTRE(params[i]);
	if ((CARRY = ISREG(params[2])))
		SETREGISTRE(params[2], params[0] | params[1]);
	else
		return (0);
	FLAG = 0;
	return (1);
}
