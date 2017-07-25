
#include "vm.h"

void	ld(t_battle *battle, t_command *c)
{
	if (ISREG(c->params[1]))
	{
		SETREGISTRE(c->params[1], c->params[0]);
		CARRY = !GETREGISTRE(c->params[1]);
	}
}
