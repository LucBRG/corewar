/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:17:28 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 14:51:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			zjmp(t_battle *battle, int ind, int a, int b)
{
	ind += a + b;
	if (CARRY == 1)
		PC = (PC + ind) % MEM_SIZE;
}
