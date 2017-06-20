/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:33:20 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/15 20:49:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				and_ft(t_battle *battle, int params[3], int size[3])
{
	int i;

	i = -1;
	while (++i < 2)
		if (size[i] == 1 && !ISREG(params[i]))
			return (0);
		else if (size[i] == 1)
			params[i] = REGISTRE(params[i]);
	if ((CARRY = ISREG(params[2])))
		REGISTRE(params[2]) = params[0] & params[1];
	return (CARRY);
}
