/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:43:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 15:41:28 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ldi(t_battle *battle, int ind1, int ind2, int reg)
{
	int	ret;
	uc	str[4];

	ret = ind1 + ind2;
	REGISTRE(reg % IDX_MOD) = chartoint(getmemory
	(battle, (PC + ret) % MEM_SIZE, str, 4), 4);
}
