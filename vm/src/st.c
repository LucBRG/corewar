
#include "vm.h"

int			st(t_battle *battle, int params[3], int size[3])
{
	uc *str;

	if (size[1] == 1 && !ISREG(params[1]))
		return (0);
	if (size[1] == 1 && ISREG(params[1]))
		params[1] = REGISTRE(params[1]);
	if (ISREG(params[0]))
	{
		params[0] = REGISTRE(params[0]);
		str = (uc*)inttochar(&params[0]);
		setmemory(battle, SETPC(params[1] % IDX_MOD), str, sizeof(int));
	}
	else
		return (0);
	FLAG = 0;
	return (1);
}
