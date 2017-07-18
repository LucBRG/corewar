
#include "vm.h"

int			live(t_battle *battle, int params[3], int size[3])
{
	int i;

	i = -1;
	if (size)
		;
	while (++i < battle->bots.nb)
		if (battle->bots.tab[i]->id == params[0])
			battle->bots.tab[i]->live++;
	FLAG = 0;
	return (1);
}
