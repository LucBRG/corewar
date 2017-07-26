
#include "vm.h"

int			check_params(t_battle *battle, int param, int size)
{
	if (size == 1 && ISREG(param))
		return (GETREGISTRE(param));
	return (param);
}
