/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:40:31 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/19 18:59:04 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "vm.h"
# include <ncurses.h>

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

# define NBOTS			battle->bots.nb
# define VIEWMEM		battle->view->windows[0]
# define VMEM			battle->view->mem
# define VCOLOR			battle->view->memcolor

enum{NOT,
	BLUE_BACK, GREEN_BACK, RED_BACK, YELLOW_BACK, 
	BLUE_PC, GREEN_PC, RED_PC, YELLOW_PC,
	BLUE_LAST, GREEN_LAST, RED_LAST, YELLOW_LAST
};

typedef struct s_battle t_battle;

typedef struct	s_view {
	WINDOW		**windows;
	int			width;
	int			height;
	char		*mem;
	char		*memcolor;
}				t_view;

t_view	*initview(t_battle *battle);
void	delview(t_battle *battle);
void	showallview(t_battle *battle);
void	ft_getcolor_mem(t_battle *battle);
void	color_pc(t_battle *battle);
void	showbot(t_battle *battle);

#endif
