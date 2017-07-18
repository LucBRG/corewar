
#include "vm.h"

int				ld(t_battle *battle, int params[3], int size[3])
{
	// ft_printf("params\t: %d\t%d\t%d\n", params[0], params[1], params[2]);
	// printf("passe\n");
	if (size)
		;
	if ((CARRY = ISREG(params[1])))
		REGISTRE(params[1]) = params[0] % IDX_MOD;
	else
		return (0);
	FLAG = 0;
		// ft_printf("passe\n");
	// ft_printf("reg 8 = %d\n", REGISTRE(params[1]));
	return (1);
	// else
	// 	printf("valeur reg %.2d = %.2d\n", REGISTRE(reg), param);
	// return (CARRY);
}
