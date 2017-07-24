/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/24 11:52:33 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

int				lldi(t_battle *battle, int params[3], int size[3])
{
	uc	str[SIZE];
	int	i;

	i = -1;
	while (++i < 3)
		if (size[i] == T_REG && !ISREG(params[i]))
			return (0);
		else if (size[i] == T_REG)
			params[i] = GETREGISTRE(params[i]);
	getmemory(battle, SETPC((params[0] + params[1])), str, SIZE);
	SETREGISTRE(params[2], chartoint(str, SIZE));
	FLAG = 0;
	return (1);
}
