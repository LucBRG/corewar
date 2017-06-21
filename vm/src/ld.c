/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:36:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/21 18:34:15 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ld(t_battle *battle, int params[3], int size[3])
{
	// ft_printf("params\t: %d\t%d\t%d\n", params[0], params[1], params[2]);
	// printf("passe\n");
	if (size)
		;
	if ((CARRY = ISREG(params[1])))
		REGISTRE(params[1]) = params[0] % IDX_MOD;
	// ft_printf("reg 8 = %d\n", REGISTRE(params[1]));
	return (5);
	// else
	// 	printf("valeur reg %.2d = %.2d\n", REGISTRE(reg), param);

}
