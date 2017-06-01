/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:24:55 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/01 10:27:19 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		setmemory(t_battle *b, int index, char *s, int len)
{
	int i;

	i = -1;
	if (!b || !s || len <= 0 || MEM_SIZE <= 0)
		return (0);
	while (++i < len)
		b->memory[(index + i) % MEM_SIZE] = s[i];
	return (1);
}

char	*getmemory(t_battle *b, int index, char *buff, int len)
{
	int i;

	i = -1;
	if (!b || !buff || len <= 0 || MEM_SIZE <= 0)
		return (NULL);
	while (++i < len)
		buff[i] = b->memory[(index + i) % MEM_SIZE];
	return (buff);
}
