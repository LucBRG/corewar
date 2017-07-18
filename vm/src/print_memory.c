/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:45:54 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/18 21:31:55 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define RST		"\033[0m"
#define HEXA(n)	((n >= 10) ? n - 10 + 'a' : n + '0')

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
	ft_printf("\n");
	// ft_printf("\nreg 9 = %.2x\n", REGISTRE(9));
	// ft_printf("id = %d\n", battle->bot->id);
}

void	ft_octethexa(char *src, char o)
{
	char q1;
	char q2;

	q1 = o >> 4 & 0xf;
	q2 = o & 0x0f;
	src[0] = HEXA(q1);
	src[1] = HEXA(q2);
}

char	*ft_strhexa(unsigned char *str, int len)
{
	int		i;
	char	*mem;

	i = -1;
	if (!(mem = ft_strnew(len * 3)))
		return (NULL);
	while (++i < len)
	{
		ft_octethexa(mem + i * 3, str[i]);
		if (i)
			mem[i * 3 - 1] = ' ';
	}
	return (mem);
}
