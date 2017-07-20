/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:26:09 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/20 16:14:39 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

#define SPEED		battle->view->speed
#define STEP		10
#define MINSPEED	STEP
#define MAXSPEED	500

void	controls(t_battle *battle)
{
	int c;
	int tmp;

	tmp = 1;
	while (battle->view->pause || tmp)
	{
		c = getch();
		if (c == ' ')
			battle->view->pause = 1 - battle->view->pause;
		else if (c == '-' && SPEED > MINSPEED)
			SPEED -= STEP;
		else if (c == '+' && SPEED < MAXSPEED)
			SPEED += STEP;
		else if (c == '.')
			return ;
		tmp = 0;
	}
}