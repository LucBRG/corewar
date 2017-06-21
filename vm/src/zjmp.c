
#include "vm.h"

int				zjmp(t_battle *battle, int params[3], int size[3])
{
	if (CARRY && size[2] == T_IND)
		PC = SETPC(params[2]);
	return (20);
}
