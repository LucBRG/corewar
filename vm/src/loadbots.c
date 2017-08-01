
#include "vm.h"

int		getidparam(char **av, int i)
{
	int id;

	id = 0;
	if (i - 2 >= 0 && ft_strequ(av[i - 2], "-n"))
		id = ft_atoi(av[i - 1]);
	return (id);
}

int		checkid(t_bots *bots, int id)
{
	int i;

	i = -1;
	while (++i < bots->nb)
		if (bots->tab[i]->id == id)
			return (0);
	return (1);
}

int		getuniqid(char **av, int i, t_bots *bots)
{
	static int id = 0;
	int	idtmp;

	idtmp = getidparam(av, i);
	if (idtmp)
		return (idtmp);
	else
		while (!checkid(bots, --id));
	return (id);
}

int		checkids(t_bots *bots)
{
	int i;
	int j;

	i = -1;
	while (++i < bots->nb)
	{
		j = i;
		while (++j < bots->nb)
			if (bots->tab[i]->id == bots->tab[j]->id)
				return (0);
	}
	return (1);
}

t_bots	loadbots(int ac, char **av)
{
	int		i;
	t_bot	*tmp;
	t_bots	bots;

	i = 0;
	bots.nb = 0;
	while (++i < ac && bots.nb < MAX_PLAYERS)
	{
		if (av[i][0] != '-' && (tmp = creabot(av[i])))
		{
			bots.tab[bots.nb] = tmp;
			bots.tab[bots.nb]->id = getuniqid(av, i, &bots);
			bots.tab[bots.nb]->rid = bots.nb;
			bots.nb++;
		}
	}
	if (!checkids(&bots))
	{
		ft_printf("error id\n");
		bots.nb = 0;
	}
	return (bots);
}
