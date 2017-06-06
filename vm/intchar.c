/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:17:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/06 15:18:51 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*inttochar(int *i)
{
	char tmp[5];

	ft_bzero(tmp, 5);
	ft_memcpy(tmp, (char*)i, 4);
	ft_memcpy((char*)i, ft_strrev(tmp), 4);
	return ((char*)i);
}

int		chartoint(unsigned char *t, int len)
{
	int i;
	int tmp;

	i = -1;
	tmp = 0;
	while (++i < len && i < sizeof(int))
		tmp |= t[i] << (((len - 1) * 8) - (i * 8));
	return (tmp);
}
