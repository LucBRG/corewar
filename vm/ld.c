/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:36:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:52:40 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ld(t_battle *battle, int param, int reg, int a)
{
	a = 0;
	if ((CARRY = ISREG(reg)))
		REGISTRE(reg) = param % IDX_MOD;
}
