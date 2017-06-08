/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:36:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 14:46:12 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ld(t_battle *battle, int param, int reg, int a)
{
	REGISTRE(reg + a) = param % IDX_MOD;
	CARRY = CHANGE(CARRY);
}
