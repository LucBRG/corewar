
#include "vm.h"

#define LASTREG	battle->cur_process->last_action[2] + 1

int				zjmp(t_battle *battle, int params[3], int size[3])
{
	// ft_printf("last action = %d\n valeur = %d\n", LASTREG + 1,GETREGISTRE(LASTREG + 1));
	if (CARRY && size[0] == T_DIR &&
		((LASTREG > 0 && LASTREG <= REG_NUMBER) && !GETREGISTRE(LASTREG)))
		PC = SETPC(params[0]);
	FLAG = 0;
	return (1);
}
