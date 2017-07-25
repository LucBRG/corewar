/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:14:27 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:26:49 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	or_ft(t_battle *battle, t_command *c)
{
	int i;

	i = -1;
	while (++i < 2)
		if (c->size[i] == T_REG && !ISREG(c->params[i]))
			return ;
		else if (c->size[i] == 1)
			c->params[i] = GETREGISTRE(c->params[i]);
	if (ISREG(c->params[2]))
	{
		SETREGISTRE(c->params[2], c->params[0] | c->params[1]);
		CARRY = !GETREGISTRE(c->params[2]);
	}
}
