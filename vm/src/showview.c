/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showview.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:34:51 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/25 13:00:44 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	setvcolor(t_battle *battle, int index, int color, int len)
{
	int i;

	i = -1;
	while (++i < len)
		VCOLOR[mod(index + i, MEM_SIZE)] = color;
}

void	showmemory(t_battle *battle)
{
	int		i;
	int		len;
	int		color;
	char	*tmp;

	i = 0;
	color = 0;
	ft_memcpy(VCOLOR, battle->print_mem, MEM_SIZE);
	ft_color_mem(battle);
	tmp = ft_strhexa((uc*)battle->memory, MEM_SIZE);
	len = ft_strlen(tmp);
	wmove(VIEWMEM, 1, 2);
	while (i < len)
	{
		if (color != VCOLOR[i / 3])
		{
			color = VCOLOR[i / 3];
			if (!color)
				wattron(VIEWMEM, COLOR_PAIR(COLOR_NOT));
			else
				wattron(VIEWMEM, COLOR_PAIR((VCOLOR[i / 3])));
		}
		if (!(i % (COL1_W - 3)))
			wmove(VIEWMEM, (1 + i / (COL1_W - 3)), 2);
		waddnstr(VIEWMEM, tmp + i, 3);
		i += 3;
	}
	wrefresh(VIEWMEM);
	ft_strdel(&tmp);
}

void	showallview(t_battle *battle)
{
	if (!battle->view)
		return ;
	showbot(battle);
	showmemory(battle);
	mvprintw(0, 10, " Speed : %d/s    Total cycle : %6d    Cycle : %4d    Limit : %4d    Check : %4d ",
		battle->view->speed, battle->fight.totalloop, battle->fight.loop, battle->fight.limitloop,
		battle->fight.cycle);
	mvprintw(0, COL2_X + 10, " Dernier joueur rapporte vivant : %s ",
		(battle->fight.last_live) ? battle->fight.last_live->name : "");
	controls(battle);
	usleep(SECONDS / battle->view->speed);
}
