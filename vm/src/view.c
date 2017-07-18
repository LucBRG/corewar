/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:40:12 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/18 21:37:19 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

#define HEIGHT			66
#define WIDTH			200

#define COL1_X			0
#define COL1_Y			0
#define COL1_W			(32 * 3 + 3)
#define COL1_H			(HEIGHT)

#define COL2_X			(COL1_X + COL1_W)
#define COL2_W			(WIDTH - COL2_X)
#define COL2_H			(HEIGHT / 4)
#define COL2_Y			((i - 1) * COL2_H)

void	init_color_view(t_view *view)
{
	curs_set(0);
	init_color(COLOR_WHITE, 700, 700, 700);
	init_pair(100, COLOR_WHITE, COLOR_BLACK);
	init_pair(BLUE_BACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(BLUE_PC, COLOR_BLACK, COLOR_BLUE);
	init_pair(BLUE_LAST, COLOR_WHITE, COLOR_BLUE);
	init_pair(GREEN_BACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(GREEN_PC, COLOR_BLACK, COLOR_GREEN);
	init_pair(GREEN_LAST, COLOR_WHITE, COLOR_GREEN);
	init_pair(RED_BACK, COLOR_RED, COLOR_BLACK);
	init_pair(RED_PC, COLOR_BLACK, COLOR_RED);
	init_pair(RED_LAST, COLOR_WHITE, COLOR_RED);
	init_pair(YELLOW_BACK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(YELLOW_PC, COLOR_BLACK, COLOR_YELLOW);
	init_pair(YELLOW_LAST, COLOR_WHITE, COLOR_YELLOW);
	view->mem = NULL;
	view->memcolor = NULL;
}

t_view	*view(t_battle *battle)
{
	t_view	*view;
	int		i;

	i = -1;
	if (!(view = (t_view*)malloc(sizeof(t_view)))
		|| !(view->windows = (WINDOW**)malloc(sizeof(WINDOW*) * NBOTS)))
		return (NULL);
	battle->view = view;
	initscr();
	if (has_colors())
	{
    	start_color();
		init_color_view(view);
	}
	view->width = WIDTH;
	view->height = HEIGHT;
	while (++i < 1 + NBOTS)
	{
		view->windows[i] = (!i)
			? subwin(stdscr, COL1_H, COL1_W, COL1_Y, COL1_X)
			: subwin(stdscr, COL2_H, COL2_W, COL2_Y, COL2_X);
		box(view->windows[i], ACS_VLINE, ACS_HLINE);
		wrefresh(view->windows[i]);
	}
	return (view);
};

void	delview(t_battle *battle)
{
	int i;

	i = -1;
    endwin();
	while (++i < NBOTS)
		free(battle->view->windows[i]);
	free(battle->view);
}

void	showmemory(t_battle *battle)
{
	int		i;
	int		color;
	char	*tmp;

	i = -1;
	color = 0;
	ft_getcolor_mem(battle);
	tmp = ft_strhexa((uc*)VMEM, MEM_SIZE);
	move(1, 2);
	while (++i < (int)ft_strlen(tmp))
	{
		if (color != VCOLOR[i / 3])
		{
			color = VCOLOR[i / 3];
			if (!color)
				attron(COLOR_PAIR(100));
			else
				attron(COLOR_PAIR((VCOLOR[i / 3])));
		}
		if (!(i % (COL1_W - 3)))
			move((1 + i / (COL1_W - 3)), 2);
		addch(tmp[i]);
	}
	wrefresh(VIEWMEM);
	ft_strdel(&tmp);
}