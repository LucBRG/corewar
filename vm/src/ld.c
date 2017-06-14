/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:36:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/14 21:58:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ld(t_battle *battle, int params[3], int size[3])
{
	// printf("reg %.2d = %.2d\n", reg, param);
	if (size)
		;
	if ((CARRY = ISREG(params[1])))
		REGISTRE(params[1]) = params[0] % IDX_MOD;
	// else
	// 	printf("valeur reg %.2d = %.2d\n", REGISTRE(reg), param);

}
