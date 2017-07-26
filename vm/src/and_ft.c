
#include "vm.h"

void	and_ft(t_battle *battle, t_command *c)
{
	int i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == 1 && !ISREG(c->params[i]))
			return ;
		else if (i < 2 && c->type[i] == REG_CODE)
			c->params[i] = GETREGISTRE(c->params[i]);
	SETREGISTRE(c->params[2], c->params[0] & c->params[1]);
	CARRY = !GETREGISTRE(c->params[2]);
}
