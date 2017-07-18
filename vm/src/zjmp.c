
#include "vm.h"

int				zjmp(t_battle *battle, int params[3], int size[3])
{
	if (CARRY && size[0] == T_DIR)
		PC = SETPC(params[0]);
	FLAG = 0;
	return (1);
}
