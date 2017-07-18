
#include "vm.h"

int			stun(t_battle *battle)
{
	int tab[16] = {10, 5, 5, 10, 10, 6, 7, 8, 20, 25, 25, 800, 10, 50, 5, 2};

	// ft_printf("INST = %d\n", INST);
	battle->cur_process->stun = tab[INST - 1];
	FLAG = 1;
	return (0);
}
