/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:33:20 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/14 18:25:01 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			and_ft(t_battle *battle, int *params)
{
	if ((CARRY = ISREG(params[0])))
		REGISTRE(params[0]) = params[1] & params[2];
}
