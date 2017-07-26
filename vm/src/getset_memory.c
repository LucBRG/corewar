
#include "vm.h"

int			mod(int a, int b)
{
	int ret;

	if (b < 0)
		return (mod(a, -b));
	ret = a % b;
	if (ret < 0)
		ret += b;
	return (ret);
}

int			setmemory(t_battle *battle, int index, uc *s, int len)
{
	int i;

	i = -1;
	if (!battle || !s || len <= 0 || MEM_SIZE <= 0)
		return (0);
	while (++i < len)
	{
		battle->memory[mod(index + i, MEM_SIZE)] = s[i];
		battle->print_mem[mod(index + i, MEM_SIZE)] =
			(char)(1 + battle->cur_process->bot->rid);
	}
	battle->cur_process->last_action[0] = index;
	battle->cur_process->last_action[1] = len;
	return (1);
}

uc			*getmemory(t_battle *battle, int index, uc *buff, int len)
{
	int i;

	i = -1;
	if (!battle || !buff || len <= 0 || MEM_SIZE <= 0)
		return (buff);
	while (++i < len)
		buff[i] = battle->memory[mod(index + i, MEM_SIZE)];
	return (buff);
}
