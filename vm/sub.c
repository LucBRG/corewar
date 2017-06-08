/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:14 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 14:49:23 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			sub(t_battle *battle, int reg1, int reg2, int reg3)
{
	REGISTRE(reg3) = REGISTRE(reg1) - REGISTRE(reg2);
	CARRY = CHANGE(CARRY);
}
