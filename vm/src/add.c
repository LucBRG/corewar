/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:47:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/17 10:15:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				add(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	if ((CARRY = (ISREG(params[0]) && ISREG(params[1]) && ISREG(params[2]))))
		REGISTRE(params[2]) = REGISTRE(params[0]) + REGISTRE(params[1]);
	else
		return (0);
	FLAG = 0;
	return (0);
}
