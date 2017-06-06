/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:47:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/06 18:02:28 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			add(t_battle *battle, int reg1, int reg2, int reg3)
{
	REGISTRE(reg3) = REGISTRE(reg1) + REGISTRE(reg2);
}
