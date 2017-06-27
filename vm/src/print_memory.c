/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:45:54 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/14 21:59:24 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define RST		"\033[0m"

void			print_memory(t_battle *battle)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		// if (battle->memory[i] > 0)
			ft_printf("\e[38;5;%dm%.2x "RST, ((battle->print_mem[i] == 0) ? 255 : battle->print_mem[i] % 255),
			battle->memory[i]);
		// else
			// ft_printf(RST"%.2x", b->print_mem[i]);
	}
	// ft_printf("\nreg 9 = %.2x\n", REGISTRE(9));
	// ft_printf("id = %d\n", battle->bot->id);
}
