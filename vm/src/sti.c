/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:34:22 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_battle *battle, t_command *c)
{
	uc	*str;
	int	i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == T_REG && !ISREG(c->params[i]))
			return ;
		else if (c->size[i] == T_REG)
			c->params[i] = GETREGISTRE(c->params[i]);
	str = (uc*)inttochar(&c->params[0]);
	setmemory(battle, SETPC(c->params[1] + c->params[2]), str, sizeof(int));
}
