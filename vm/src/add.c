/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:47:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/24 11:50:48 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				add(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	if ((CARRY = (ISREG(params[0]) && ISREG(params[1]) && ISREG(params[2]))))
		SETREGISTRE(params[2], GETREGISTRE(params[0]) + GETREGISTRE(params[1]));
	else
		return (0);
	FLAG = 0;
	return (0);
}
