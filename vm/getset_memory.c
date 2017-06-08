
#include "vm.h"

int	mod(int a, int b)
{
	int ret;

	if(b < 0)
		return mod(a, -b);
	ret = a % b;
	if(ret < 0)
		ret += b;
	return ret;
}

int			setmemory(t_battle *b, int index, uc *s, int len)
{
	int i;

	i = -1;
	// ft_printf("set memory :\nindex : %d\tlen : %d\tmem : %.8x\n", index, len, *(unsigned int*)s);
	if (!b || !s || len <= 0 || MEM_SIZE <= 0)
		return (0);
	while (++i < len)
	{
		b->memory[mod(index + i, MEM_SIZE)] = s[i];
		if (b->cur_process)
			b->print_mem[mod(index + i, MEM_SIZE)] = (char)ID;
	}
	return (1);
}

uc			*getmemory(t_battle *b, int index, uc *buff, int len)
{
	int i;

	i = -1;
	if (!b || !buff || len <= 0 || MEM_SIZE <= 0)
		return (buff);
	while (++i < len)
		buff[i] = b->memory[mod(index + i, MEM_SIZE)];
	return (buff);
}
