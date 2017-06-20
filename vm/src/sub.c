/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:14 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 17:38:41 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			sub(t_battle *battle, int reg1, int reg2, int reg3)
{
	if ((CARRY = (ISREG(reg1) && ISREG(reg2) && ISREG(reg3))))
		REGISTRE(reg3) = REGISTRE(reg1) - REGISTRE(reg2);
}