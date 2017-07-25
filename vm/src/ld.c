
#include "vm.h"

int				ld(t_battle *battle, int params[3], int size[3])
{
	if (size)
		;
	if ((CARRY = ISREG(params[1])))
		SETREGISTRE(params[1], params[0]);
	else
		return (0);
	return (1);
}
