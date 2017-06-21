/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:21:26 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/21 18:50:24 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define INST		battle->memory[PC]
#define OCP			battle->memory[PC + 1]
#define PARAMS		battle->memory[(PC + (isocp(INST) ? 2 : 1))]
#define PARAM(n)	(OCP >> ((n + 1) * 2) & 0b11)

int		isocp(char inst)
{
	return (inst == LD || inst == ST || inst == ADD || inst == SUB
		|| inst == AND || inst == OR || inst == XOR || inst == LDI
		|| inst == STI || inst == LLD || inst == LLDI);
}

void	size_p(t_battle *battle, int (*sizep)[3])
{
	int i;

	i = -1;
	ft_bzero(sizep, sizeof(int) * 3);
	if (INST == AFF)
		(*sizep)[0] = T_REG;
	else if (INST == LIVE || INST == ZJMP || INST == FORK || INST == LFORK)
		(*sizep)[0] = T_DIR;
	else
		while (++i < 3)
			(*sizep)[i] = (PARAM(i) != 3) ? PARAM(i) : 4;
}

void	params_p(t_battle *battle, int (*params)[3], int sizep[3])
{
	int i;

	i = -1;
	(*params)[2] = chartoint(&PARAMS, sizep[0]);
	(*params)[1] = chartoint(&PARAMS + sizep[0], sizep[1]);
	(*params)[0] = chartoint(&PARAMS + sizep[0] + sizep[1], sizep[2]);
}

int		load_func(t_battle *battle)
{
	int i;
	int pc;
	int params[3];
	int sizep[3];

	pc = PC;
	ft_bzero(params, sizeof(int) * 3);
	if ((INST > 0 && INST <= 16) && !((isocp(INST) && !check_ocp(INST, OCP))))
	{
		// ft_printf("check ocp = %d\n", check_ocp(INST, OCP));
		// ft_printf("isocp = %d\n", isocp(INST));
		// ft_printf("opc = %d\n", C(R, R, Z));
		size_p(battle, &sizep);
		params_p(battle, &params, sizep);
		// ft_printf("params\t: %d\t%d\t%d\t%d\n", INST, params[0], params[1], params[2]);
		// ft_printf("sizep\t: %d\t%d\t%d\t%d\n", MAX((sizep[0] + sizep[1] + sizep[2]), 1), sizep[0], sizep[1], sizep[2]);
		// ft_printf("pass\n");
		if (!(battle->cur_process->stun = battle->func[INST - 1](battle, params, sizep)))
			return (1);
		// ft_printf("pc = %d\n", pc);
		// ft_printf("PC = %d\n", PC);
		if (pc != PC)
			return (0);
	}
	else
		return (1);
	i = 1 + isocp(INST) + sizep[0] + sizep[1] + sizep[2];
	// i = ((pc == PC) ? MAX((1 + sizep[0] + sizep[1] + sizep[2]), 1) : 0);
	// i += ((isocp(INST) && ((pc == PC) ? MAX((1 + sizep[0] + sizep[1] + sizep[2]), 1) : 0)) ? 1 : 0);
	// ft_printf("i = %d\n", i);
	return (i);
}
