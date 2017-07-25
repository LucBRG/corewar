
#include "vm.h"

void	and_ft(t_battle *battle, t_command *c)
{
	int i;

	i = -1;
	while (++i < 2)
		if (c->size[i] == 1 && !ISREG(c->params[i]))
			return ;
		else if (c->size[i] == 1)
			c->params[i] = GETREGISTRE(c->params[i]);
	if (ISREG(c->params[2]))
	{
		SETREGISTRE(c->params[2], c->params[0] & c->params[1]);
		CARRY = !GETREGISTRE(c->params[2]);
	}
}
