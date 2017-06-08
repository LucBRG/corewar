/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:45:54 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/08 18:19:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define RST		"\033[0m"

void			print_memory(t_battle *b)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (b->print_mem[i] > 0)
			ft_printf("\e[38;5;%dm%.2x"RST, ID, b->print_mem[i]);
		else
			ft_printf(RST"%.2x", b->print_mem[i]);
	}
}
