
#include "vm.h"

void	live(t_battle *battle, t_command *c)
{
	int i;

	i = -1;
	while (++i < battle->bots.nb)
	{
		if (battle->bots.tab[i]->id == c->params[0])
		{
			battle->cur_process->live++;
			battle->fight.last_live = battle->bots.tab[i];
		}
	}
}
