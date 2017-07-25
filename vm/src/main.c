
#include "vm.h"

#define ISFLAG(l)	(!!ft_strchr(av[i], l))

void	initoptions(int ac, char **av, t_battle *battle)
{
	int i;

	i = 0;
	while (++i < ac)
		if (av[i][0] == '-')
		{
			battle->opts.ncurses = ISFLAG('n');
			if (ISFLAG('v') && i + 1 < ac)
				battle->opts.verbose = ft_atoi(av[i + 1]);
		}
}

void getoptions(t_battle *battle)
{
	if (battle->opts.ncurses)
		battle->view = initview(battle);
}

int	main(int ac, char **av)
{
	int			i;
	t_battle	*b;
	i = -1;

	if (!(b = initbattle(ac, av)))
		return (0);
	initoptions(ac, av, b);
	getoptions(b);
	// ft_printf("%s\n", ft_string_memory(b));
	// printf("FIGHT\t%d\n", b->bots.nb);
	// ft_printf("%d\n", 4294904660);
	// print_memory(b);
	if (b->bots.nb)
	{
		// ft_lstiter(b->process, displayprocess);
		battle_launch(b);
		viewfinnish(b);
		if (b->fight.last_live)
			ft_printf("le joueur %d(%s) a gagne\n",
				-(b->fight.last_live->id), b->fight.last_live->name);
	}
	return (0);
}
