
#include "vm.h"

int			stun(t_battle *battle, t_command *c)
{
	static int tab[16] = {10, 5, 5, 10, 10, 6, 7, 8, 20, 25, 25, 800, 10, 50,
						1000, 2};

	if (c->inst >= 1 && c->inst <= 16)
	{
		battle->cur_process->stun = tab[c->inst - 1] - 2;
		FLAG = 1;
	}
	return (0);
}
