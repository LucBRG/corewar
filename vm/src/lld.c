/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:39:26 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/22 17:35:40 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				lld(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	if ((CARRY = ISREG(params[1])))
		REGISTRE(params[1]) = params[0];
	else
		return (0);
	return (10);
}
