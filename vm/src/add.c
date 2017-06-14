/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:47:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/14 18:25:20 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			add(t_battle *battle, int *params)
{
	if ((CARRY = (ISREG(params[1]) && ISREG(params[2]) && ISREG(params[3]))))
		REGISTRE(params[3]) = REGISTRE(params[1]) + REGISTRE(params[2]);
}
