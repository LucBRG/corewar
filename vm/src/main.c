
#include "vm.h"

#define NCURSES			(1 << 0)
#define ISFLAG(l, ret)	((ft_strchr(av[i], l)) ? ret : 0)

int	initoptions(int ac, char **av)
{
	int i;
	int options;

	i = 0;
	options = 0;
	while (++i < ac)
		if (av[i][0] == '-')
		{
			options |= ISFLAG('n', NCURSES);
		}
	return options;
}

void getoptions(t_battle *battle, int options)
{
	if (options & NCURSES)
		battle->view = initview(battle);
}

int	main(int ac, char **av)
{
	int			i;
	t_process	*win;
	t_battle	*b;

	i = -1;
	if (!(b = initbattle(ac, av)))
		return (0);
	getoptions(b, initoptions(ac, av));
	// ft_printf("%s\n", ft_string_memory(b));
	// printf("FIGHT\t%d\n", b->bots.nb);
	// ft_printf("%d\n", 4294904660);
	// print_memory(b);
	if (b->bots.nb)
	{
		// ft_lstiter(b->process, displayprocess);
		win = battle_launch(b);
		if (win)
			printf("le joueur %d(%s) a gagne\n", win->bot->id, win->bot->name);
	}
	// print_memory(b);
	// displayprocess(b->process);
	// ft_printf("\nreg 3 = %u", b->cur_process->registre[3]);
	delview(b);
	ft_printf("le joueur %d(%s) a gagne\n",
		-(b->fight.last_live->id), b->fight.last_live->name);
	return (0);
}
