/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:43:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/15 21:57:44 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

int				ldi(t_battle *battle, int params[3], int size[3])
{
	uc	str[SIZE];
	int	i;

	i = -1;
	while (++i < 3)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
		else if (size[i] == T_REG)
			params[i] = REGISTRE(params[i]);
	getmemory(battle, SETPC((params[0] + params[1]) % IDX_MOD), str, SIZE);
	REGISTRE(params[2]) = chartoint(str, SIZE);
	return (1);
}
