/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:25:57 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

void	lldi(t_battle *battle, t_command *c)
{
	uc	str[SIZE];
	int	i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == T_REG && !ISREG(c->params[i]))
			return ;
		else if (c->size[i] == T_REG)
			c->params[i] = GETREGISTRE(c->params[i]);
	getmemory(battle, SETPC((c->params[0] + c->params[1])), str, SIZE);
	SETREGISTRE(c->params[2], chartoint(str, SIZE));
	CARRY = !GETREGISTRE(c->params[2]);
}
