
#include "vm.h"

int				and_ft(t_battle *battle, int params[3], int size[3])
{
	int i;

	i = -1;
	while (++i < 2)
		if (size[i] == 1 && !ISREG(params[i]))
			return (0);
		else if (size[i] == 1)
			params[i] = REGISTRE(params[i]);
	if ((CARRY = ISREG(params[2])))
		REGISTRE(params[2]) = params[0] & params[1];
	else
		return (0);
	FLAG = 0;
	return (1);
}
