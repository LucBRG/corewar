
#include "vm.h"

void	zjmp(t_battle *battle, t_command *c)
{
	if (CARRY)
		PC = SETPC(c->params[0]);
}
