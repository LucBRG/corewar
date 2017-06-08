/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:21:26 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/08 14:22:18 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define INST		battle->memory[PC]
#define OCP			battle->memory[PC + 1]
#define PARAMS		battle->memory[PC + 2]
#define PARAM(n)	(OCP >> ((3 - n) * 2) & 0b11)

int		isocp(char inst)
{
	return (inst == LIVE || inst == ZJMP || inst == FORK || inst == LFORK
		|| inst == AFF);
}

int		load_func(t_battle *battle)
{
	int i;
	int pc;
	int params[3];
	int sizep[3];

	i = -1;
	pc = PC;
	ft_bzero(params, sizeof(int) * 3);
	ft_bzero(sizep, sizeof(int) * 3);
	if (INST > 0 && INST <= 16)
	{
		if (INST == AFF)
			sizep[0] = T_REG;
		else if (INST == LIVE || INST == ZJMP || INST == FORK || INST == LFORK)
			sizep[0] = T_DIR;
		else
			while (++i < 3)
				sizep[i] = PARAM(i);
		params[0] = chartoint(&PARAMS, sizep[0]);
		params[1] = chartoint(&PARAMS + sizep[0], sizep[1]);
		params[2] = chartoint(&PARAMS + sizep[0] + sizep[1], sizep[2]);
		battle->func[INST - 1](battle, params[0], params[1], params[2]);
	}
	// printf("params\t: %d\t%d\t%d\t%d\n", INST, params[0], params[1], params[2]);
	// printf("sizep\t: %d\t%d\t%d\t%d\n", MAX((sizep[0] + sizep[1] + sizep[2]), 1), sizep[0], sizep[1], sizep[2]);
	i = ((pc == PC) ? MAX((1 + sizep[0] + sizep[1] + sizep[2]), 1) : 0);
	return (i + (isocp(INST) ? 1 : 0));
}
