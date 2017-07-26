
#include "vm.h"

<<<<<<< HEAD
#define ISFLAG(l)	(!!ft_strchr(av[i], l))
#define OPTS		battle->opts
=======
#define IFFLAG(l)		(!!ft_strstr(av[i], l))
>>>>>>> vm_tferrari

void	initoptions(int ac, char **av, t_battle *battle)
{
	int i;

	i = 0;
	while (++i < ac)
		if (av[i][0] == '-')
		{
<<<<<<< HEAD
			OPTS.ncurses = (!OPTS.ncurses) ? ISFLAG('n') : OPTS.ncurses;
			if (ISFLAG('v') && i + 1 < ac)
				battle->opts.verbose = ft_atoi(av[i + 1]);
=======
			OPTS.ncurses = (!OPTS.ncurses) ? IFFLAG("n") : OPTS.ncurses;
			if (IFFLAG("v") && i + 1 < ac)
				OPTS.verbose = ft_atoi(av[i + 1]);
			if ((OPTS.dump = IFFLAG("dump")) && i + 1 < ac)
				OPTS.n_dump = ft_atoi(av[i + 1]);
>>>>>>> vm_tferrari
		}
}

void	getoptions(t_battle *battle)
{
	if (battle->opts.ncurses)
		battle->view = initview(battle);
}

int		main(int ac, char **av, char **en)
{
	t_battle	*b;

	if (!(b = initbattle(ac, av, en)))
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
	if (b->opts.dump)
		print_memory(b);
	return (0);
}
