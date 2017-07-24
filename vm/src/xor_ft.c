/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:03:45 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/24 11:54:03 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				xor_ft(t_battle *battle, int params[3], int size[3])
{
	int i;

	i = -1;
	while (++i < 2)
		if (size[i] == 1 && !ISREG(params[i]))
			return (0);
		else if (size[i] == 1)
			params[i] = GETREGISTRE(params[i]);
	if ((CARRY = ISREG(params[2])))
		SETREGISTRE(params[2], params[0] ^ params[1]);
	else
		return (0);
	FLAG = 0;
	return (1);
}
