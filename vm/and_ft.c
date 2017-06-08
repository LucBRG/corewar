/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:33:20 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:33:42 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			and_ft(t_battle *battle, int param1, int param2, int reg)
{
	if ((CARRY = ISREG(reg)))
		REGISTRE(reg) = param1 & param2;
}
