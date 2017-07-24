/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:47 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/24 11:50:18 by dbischof         ###   ########.fr       */
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
		ft_printf("%c", GETREGISTRE(params[0]) % 256);
	FLAG = 0;
	return (1);
}
