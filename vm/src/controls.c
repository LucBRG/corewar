/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:26:09 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/20 18:14:03 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

#define SPEED		battle->view->speed
#define STEP		10
#define MINSPEED	STEP
#define MAXSPEED	500

void	msgsizescreen()
{
	const char *msg[3] = {
		"Agrandir la console",
		"Hauteur : %3d -> %3d",
		"Largeur : %3d -> %3d"
	};
	int y;

	y = LINES / 2;
	mvaddstr(y, COLS / 2 - ft_strlen(msg[0]) / 2, msg[0]);
	if (LINES < HEIGHT)
	{
		y++;
		mvprintw(y, COLS / 2 - ft_strlen(msg[1]) / 2, msg[1], LINES, HEIGHT);
	}
	if (COLS < WIDTH)
	{
		y++;
		mvprintw(y, COLS / 2 - ft_strlen(msg[2]) / 2, msg[2], COLS, WIDTH);
	}
}

int		sizescreenless(t_battle *battle)
{
	if (LINES < HEIGHT || COLS < WIDTH)
	{
		clear();
		msgsizescreen();
		battle->view->screendown = 1;
		return (1);
	}
	else
	{
		if (battle->view->screendown)
		{
			battle->view->screendown = 0;
			refreshall(battle);
		}
	}
	return (0);
}

void	controls(t_battle *battle)
{
	int c;
	int tmp;

	tmp = 1;
	while (sizescreenless(battle) || battle->view->pause || tmp)
	{
		c = getch();
		if (c == ' ')
			battle->view->pause = 1 - battle->view->pause;
		else if (c == '-' && SPEED > MINSPEED)
			SPEED -= STEP;
		else if (c == '+' && SPEED < MAXSPEED)
			SPEED += STEP;
		else if (c == '.' && battle->view->pause)
			return ;
		tmp = 0;
	}
}