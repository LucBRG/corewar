
#include "vm.h"

int				zjmp(t_battle *battle, int params[3], int size[3])
{
	if (CARRY && size[0] == T_IND)
		PC = SETPC(params[0]);
	return (CARRY);
}
