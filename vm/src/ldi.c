/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:43:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:16:47 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

void	ldi(t_battle *battle, t_command *c)
{
	uc	str[SIZE];
	int	i;

	i = -1;
	// ft_printf("param 3 = %d\n", params[2]);
	while (++i < 3)
		if (c->size[i] == T_REG && !ISREG(c->params[i]))
			return ;
	getmemory(battle, SETPC((c->params[0] + c->params[1]) % IDX_MOD), str, SIZE);
	SETREGISTRE(c->params[2], chartoint(str, SIZE));
	// ft_printf("ldi reg = %d et valeur reg = %x\n",params[2], REGISTRE(params[2]));
}
