/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmemory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:53:41 by dbischof          #+#    #+#             */
/*   Updated: 2017/06/01 10:25:16 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	loadmemory(t_battle *b)
{
	int	i;
	int	total;
	int space;

	i = -1;
	total = 0;
	while (++i < b->bots.nb)
		total += b->bots.tab[i]->nb_instructions;
	space = (MEM_SIZE - total) / b->bots.nb;
	i = -1;
	while (++i < b->bots.nb)
		ft_memcpy(b->memory + (i * space))
	return (space);
}
