/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:44:30 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/20 18:04:57 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	ft_color_mem(t_battle *battle)
{
	t_list		*elem;
	t_process	*pr;
	int			colorbase;

	elem = battle->process;
	while (elem)
	{
		pr = (t_process*)elem->content;
		colorbase = (1 + pr->bot->rid) % 4;
		VCOLOR[pr->pc] = (colorbase + 4);
		if (pr->last_action[0] != -1 && pr->last_action[0] != -1)
			ft_memset(VCOLOR + pr->last_action[0], colorbase + 8, pr->last_action[1]);
		elem = elem->next;
	}
}

void	showparam(WINDOW *win, int size, int param)
{
	if (size == 1)
		wprintw(win, "%-8.2x\t", param);
	else if (size == 2)
		wprintw(win, "%-8.4x\t", param);
	else if (size == 4)
		wprintw(win, "%-8.8x\t", param);
	else
		wprintw(win, "%-8s\t", "--");
}

void	showprocess(t_battle *battle, WINDOW *win, t_process *process, int posy)
{
	const char	*instructions[17] = {"", "LIVE", "LD", "ST", "ADD", "SUB",
		"AND", "OR", "XOR", "ZJMP", "LDI", "STI", "FORK", "LLD", "LLDI",
		"LFOR", "AFF"};
	char		tmp[10];
	char		*tmp2;
	t_command	c;
	int			i;

	i = -1;
	c = getcommand(battle, process->pc);
	ft_bzero(tmp, 10);
	getmemory(battle, process->pc, (uc*)tmp, 2);
	tmp2 = ft_strhexa((uc*)tmp, 10);
	mvwprintw(win, posy, 1, "%-3c%.2x\t%-4s\t",
		((process->dead) ? 'x' : 'v'), c.inst,
		((c.error) ? "" : instructions[c.inst]));
	while (++i < 3)
		showparam(win, c.size[i], c.params[i]);
	wprintw(win, "%4d\t%4d\t%4d",
		c.len, process->stun, process->live);
	free(tmp2);
}

void	shearchprocess(t_battle *battle, WINDOW *win, t_bot *bot)
{
	int			posy;
	t_list		*elem;
	t_process	*process;

	elem = battle->process;
	posy = 6;
	while (elem)
	{
		if (posy < 15)
		{
			process = (t_process*)elem->content;
			if (process->bot == bot && !process->dead)
			{
				showprocess(battle, win, process, posy++);
				wrefresh(win);
			}
			elem = elem->next;
		}
	}
}

void	showbot(t_battle *battle)
{
	int		i;
	WINDOW	*win;
	t_bot	*bot;

	i = -1;
	while (++i < NBOTS)
	{
		win = battle->view->windows[1 + i];
		bot = battle->bots.tab[i];
		wattron(win, COLOR_PAIR(1 + i));
		mvwprintw(win, 1, 1, "Nom\t\t: %s", bot->name);
		mvwprintw(win, 2, 1, "Description\t: %s", bot->comment);
		mvwprintw(win, 4, 1, "Processus\t:");
		mvwprintw(win, 5, 4,
			"PC\tINST\tPARAM1\t\tPARAM2\t\tPARAM3\t\tSAUT\tSTUN\tLIVE");
		shearchprocess(battle, win, bot);
		wrefresh(win);
	}
}
