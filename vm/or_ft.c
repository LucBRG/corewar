/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:14:27 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:56:06 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			or_ft(t_battle *battle, int param1, int param2, int reg)
{
	if ((CARRY = ISREG(reg)))
		REGISTRE(reg) = param1 | param2;
}
