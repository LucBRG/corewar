/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:36:46 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/18 21:46:03 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

#define IS_PC(n)		(n >= BLUE_PC && n <= YELLOW_PC)
#define IS_BACK(n)		(n >= BLUE_BACK && n <= YELLOW_BACK)
#define IS_LAST(n)		(n >= BLUE_LAST && n <= YELLOW_LAST)
#define IS_SAME(n, m)	(n && m && n % 4 == m % 4)
#define BPRINT	battle->print_mem

void	color_pc(t_battle *battle)
{
	t_list		*elem;
	t_process	*pr;

	elem = battle->process;
	while (elem)
	{
		pr = (t_process*)elem->content;
		VCOLOR[pr->pc] = (-pr->bot->id % 4 + 4);
		elem = elem->next;
	}
}

void	ft_getcolor_mem(t_battle *battle)
{
	int		i;
	char	*last;

	i = -1;
	last = VMEM;
	VMEM = ft_strnew(MEM_SIZE);
	ft_memcpy(VMEM, (char*)battle->memory, MEM_SIZE);
	if (!VCOLOR)
		VCOLOR = (char*)battle->print_mem;
	while (++i < MEM_SIZE)
	{
		if (last && VMEM[i] != last[i])
			VCOLOR[i] = BPRINT[i] % 4 + 8;
		else if (IS_PC(VCOLOR[i]) || IS_LAST(VCOLOR[i]))
			VCOLOR[i] = VCOLOR[i] % 4;
	}
	color_pc(battle);
	if (last)
		ft_strdel(&last);
}
