/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:47 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/17 10:15:43 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			aff(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	if (!ISREG(params[0]))
		return (0);
	else
		ft_printf("%c", REGISTRE(params[0]) % 256);
	FLAG = 0;
	return (1);
}
