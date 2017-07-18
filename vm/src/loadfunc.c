
#include "vm.h"

#define OCP			battle->memory[PC + 1]
#define PARAMS		battle->memory[(PC + (isocp(INST) ? 2 : 1))]
#define PARAM(n)	(OCP >> ((3 - n) * 2) & 0b11)

int		isocp(char inst)
{
	return (inst == LD || inst == ST || inst == ADD || inst == SUB
		|| inst == AND || inst == OR || inst == XOR || inst == LDI
		|| inst == STI || inst == LLD || inst == LLDI);
}

int		t_ind_size(t_battle *battle, char inst, int i)
{
	if ((inst == LD || inst == AND || inst == OR || inst == XOR ||
	inst == LLD) && PARAM(i) == T_DIR)
		return (4);
	else
		return (PARAM(i));
}

void	size_p(t_battle *battle, int (*sizep)[3])
{
	int i;

	i = -1;
	ft_bzero(sizep, sizeof(int) * 3);
	if (INST == AFF)
		(*sizep)[0] = 1;
	else if (INST == LIVE)
		(*sizep)[0] = 4;
	else if (INST == ZJMP || INST == FORK || INST == LFORK)
		(*sizep)[0] = 2;
	else
		while (++i < 3)
			(*sizep)[i] = (PARAM(i) != 3) ? t_ind_size(battle, INST, i) : 2;
}

void	params_p(t_battle *battle, int (*params)[3], int sizep[3])
{
	int i;

	i = -1;
	(*params)[0] = chartoint(&PARAMS, sizep[0]);
	(*params)[1] = chartoint(&PARAMS + sizep[0], sizep[1]);
	(*params)[2] = chartoint(&PARAMS + sizep[0] + sizep[1], sizep[2]);
}

int		load_func(t_battle *battle)
{
	int i;
	int pc;
	int params[3];
	int sizep[3];

	pc = PC;
	if ((INST > 0 && INST <= 16) && !((isocp(INST) && !check_ocp(INST, OCP))))
	{
		battle->count++;
		ft_bzero(params, sizeof(int) * 3);
		size_p(battle, &sizep);
		params_p(battle, &params, sizep);
		// ft_printf("inst\t: %d\n", INST);
		// ft_printf("params\t: %d\t%d\t%d\n", params[0], params[1], params[2]);
		// ft_printf("sizep\t: %d\t%d\t%d\n", sizep[0], sizep[1], sizep[2]);
		if (STUN == 0 && FLAG == 0)
			return (stun(battle));
		else if (STUN == 0 && FLAG == 1 && !(battle->func[INST - 1](battle, params, sizep)))
			return (1);
		// ft_printf("le stun = %d\n", battle->cur_process->stun);
		// ft_printf("pc = %d\n", pc);
		// ft_printf("passe\n");
		if (pc != PC)
			return (0);
	}
	else
		return (1);
	i = 1 + isocp(INST) + sizep[0] + sizep[1] + sizep[2];
	return (i);
}
