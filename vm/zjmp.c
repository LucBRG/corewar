/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:17:28 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 18:19:14 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> vm_tferrari
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			zjmp(t_battle *battle, int ind, int a, int b)
{
	a = b;
	if (CARRY)
		PC = SETPC(ind);
}