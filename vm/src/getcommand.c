/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:15:33 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/25 13:04:22 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define OCP			battle->memory[pc + 1]
#define PARAMS		battle->memory[(pc + ((c->isocp) ? 2 : 1))]
#define PARAM(n)	(OCP >> ((3 - n) * 2) & 0b11)

int		isocp(char inst)
{
	return (inst == LD || inst == ST || inst == ADD || inst == SUB
		|| inst == AND || inst == OR || inst == XOR || inst == LDI
		|| inst == STI || inst == LLD || inst == LLDI);
}

int		t_ind_size(t_battle *battle, char inst, int i, int pc)
{
	if ((inst == LD || inst == AND || inst == OR || inst == XOR ||
	inst == LLD) && PARAM(i) == T_DIR)
		return (4);
	else
		return (PARAM(i));
}

void	size_p(t_battle *battle, t_command *c, int pc)
{
	int i;

	i = -1;
	if (c->inst == AFF)
		c->size[0] = 1;
	else if (c->inst == LIVE)
		c->size[0] = 4;
	else if (c->inst == ZJMP || c->inst == FORK || c->inst == LFORK)
		c->size[0] = 2;
	else
		while (++i < 3)
			c->size[i] = (PARAM(i) != 3) ? t_ind_size(battle, c->inst, i, pc) : 2;
}

void	params_p(t_battle *battle, t_command *c, int pc)
{
	int i;

	i = -1;
	c->params[0] = chartoint(&PARAMS, c->size[0]);
	c->params[1] = chartoint(&PARAMS + c->size[0], c->size[1]);
	c->params[2] = chartoint(&PARAMS + c->size[0] + c->size[1], c->size[2]);
	while (++i < 3)
		c->params[i] = (c->size[i] == 2) ? (short)(c->params[i]) : c->params[i];
}

int		getindirect(t_battle *battle, int param, int pc, int l)
{
	int	index;
	uc	tmp[4];

	index = (l) ? ((pc + param) % IDX_MOD) : (pc + param);
	getmemory(battle, index, tmp, 4);
	return (chartoint(tmp, 4));
}

void	getallindirect(t_battle *battle, t_command *c, int pc)
{
	if (c->inst == LD && c->type[0] == IND_CODE)
		c->params[0] = getindirect(battle, c->params[0], pc, 0);
	else if (c->inst == LLD && c->type[0] == IND_CODE)
		c->params[0] = getindirect(battle, c->params[0], pc, 1);
	else if (c->inst == STI && c->type[1] == IND_CODE)
		c->params[1] = getindirect(battle, c->params[1], pc, 0);
}

void	gettype(t_command *c)
{
	int i;

	i = -1;
	while (++i < 3)
		c->type[i] = (c->ocp >> ((3 - i) * 2) & 0b11);
}

t_command	getcommand(t_battle *battle, int pc)
{
	t_command c;

	c.inst = MEMORY[pc];
	c.ocp = 0;
	c.len = 0;
	c.error = 0;
	c.isocp = isocp(c.inst);
	ft_bzero(c.params, sizeof(int) * 3);
	ft_bzero(c.size, sizeof(int) * 3);
	ft_bzero(c.type, sizeof(int) * 3);
	c.error |= !(c.inst >= 1 && c.inst <= 16);
	if (!c.error && c.isocp)
	{
		c.ocp = MEMORY[pc + 1];
		c.error |= !check_ocp(c.inst, c.ocp) << 1;
	}
	if (!c.error)
	{
		size_p(battle, &c, pc);
		params_p(battle, &c, pc);
		gettype(&c);
		getallindirect(battle, &c, pc);
	}
	c.len = (c.error) ? 1 : 1 + c.isocp + c.size[0] + c.size[1] + c.size[2];
	return (c);
}
