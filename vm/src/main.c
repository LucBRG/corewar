
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
	if (b->bots.nb)
	{
		battle_launch(b);
		viewfinnish(b);
		if (b->fight.last_live)
			ft_printf("le joueur %d(%s) a gagne\n",
				b->fight.last_live->id, b->fight.last_live->name);
	}
	return (0);
}
