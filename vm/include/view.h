/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:40:31 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/18 21:15:29 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "vm.h"
# include <ncurses.h>

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

t_view	*view(t_battle *battle);
void	delview(t_battle *battle);
void	showmemory(t_battle *battle);
void	ft_getcolor_mem(t_battle *battle);
void	color_pc(t_battle *battle);

#endif
