/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:47:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/25 16:31:29 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add(t_battle *battle, t_command *c)
{

	if (ISREG(c->params[0]) && ISREG(c->params[1]) && ISREG(c->params[2]))
	{
		SETREGISTRE(c->params[2],
			GETREGISTRE(c->params[0]) + GETREGISTRE(c->params[1]));
		CARRY = !GETREGISTRE(c->params[2]);
	}
}
