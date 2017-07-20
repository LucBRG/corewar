/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:43:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/20 19:18:41 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

int				ldi(t_battle *battle, int params[3], int size[3])
{
	uc	str[SIZE];
	int	i;

	i = -1;
	// ft_printf("param 3 = %d\n", params[2]);
	while (++i < 3)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
	getmemory(battle, SETPC((params[0] + params[1]) % IDX_MOD), str, SIZE);
	REGISTRE(params[2]) = chartoint(str, SIZE);
	// ft_printf("ldi reg = %d et valeur reg = %x\n",params[2], REGISTRE(params[2]));
	FLAG = 0;
	return (1);
}
