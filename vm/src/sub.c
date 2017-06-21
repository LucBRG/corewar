/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:14 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/21 18:34:55 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				sub(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	if ((CARRY = (ISREG(params[0]) && ISREG(params[1]) && ISREG(params[2]))))
		REGISTRE(params[2]) = REGISTRE(params[1]) - REGISTRE(params[0]);
	return (10);
}
