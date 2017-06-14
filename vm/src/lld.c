/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:39:26 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:47:46 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			lld(t_battle *battle, int param, int reg, int a)
{
	a = 0;
	if ((CARRY = ISREG(reg)))
		REGISTRE(reg) = param;
}
