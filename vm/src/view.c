/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:40:12 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/24 19:22:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	init_color_view()
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
}

void	initparamsview(t_battle *battle, t_view *view)
{
	int		i;

	i = -1;
	view->width = WIDTH;
	view->height = HEIGHT;
	view->memcolor = ft_strnew(MEM_SIZE);
	view->speed = 50;
	view->pause = 1;
	view->screendown = 0;
	while (++i < 1 + NBOTS)
	{
		view->windows[i] = (!i)
			? subwin(stdscr, COL1_H, COL1_W, COL1_Y, COL1_X)
			: subwin(stdscr, COL2_H, COL2_W, COL2_Y, COL2_X);
		box(view->windows[i], ACS_VLINE, ACS_HLINE);
	}
}

void	refreshall(t_battle * battle)
{
	int		i;

	i = -1;
	clear();
	while (++i < 1 + NBOTS)
	{
		battle->view->windows[i] = (!i)
			? subwin(stdscr, COL1_H, COL1_W, COL1_Y, COL1_X)
			: subwin(stdscr, COL2_H, COL2_W, COL2_Y, COL2_X);
		box(battle->view->windows[i], ACS_VLINE, ACS_HLINE);
		wrefresh(battle->view->windows[i]);
	}
	refresh();
}

t_view	*initview(t_battle *battle)
{
	t_view	*view;
	if (!(view = (t_view*)malloc(sizeof(t_view)))
		|| !(view->windows = (WINDOW**)malloc(sizeof(WINDOW*) * NBOTS)))
		return (NULL);
	initscr();
	cbreak();
	noecho();
	timeout(0);
	if (has_colors())
	{
    	start_color();
		init_color_view();
	}
	initparamsview(battle, view);
	return (view);
};

void	delview(t_battle *battle)
{
	int i;

	i = -1;
	if (!battle->view)
		return ;
	curs_set(1);
    endwin();
    free(VCOLOR);
	while (++i < NBOTS)
		free(battle->view->windows[i]);
	free(battle->view);
}
