/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:24:55 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/01 12:00:48 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	mod(int a, int b)
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
	printf("index\t: %d\nlen\t: %d\nmem\t: %d\n", index, len, mod(index, MEM_SIZE));
	if (!b || !s || len <= 0 || MEM_SIZE <= 0)
		return (0);
	while (++i < len)
		b->memory[mod(index + i, MEM_SIZE)] = s[i];
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
