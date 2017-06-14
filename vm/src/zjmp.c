
#include "vm.h"

void			zjmp(t_battle *battle, int ind, int a, int b)
{
	a = b;
	if (CARRY)
		PC = SETPC(ind);
}
