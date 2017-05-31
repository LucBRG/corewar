/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_battle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:25:43 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/31 15:37:24 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_BATTLE_H
# define VM_BATTLE_H

# include "libft.h"
# include "ft_printf.h"
# include "stdio.h"
# include "op.h"
# include "vm.h"

typedef struct	s_battle
{
	char		memory[30];
	t_proc		*cur_proc;
	char		*begin_mem;
	int			reg[REG_NUMBER];
	t_bots		*bots;
}				t_battle;

typedef struct	s_proc
{
	char		registre[REG_NUMBER * REG_SIZE];
	char		*pc;
	char		carry;
	t_bot		*bot;
}				t_proc;

void			sti(t_battle *battle, int reg, int ind1, int ind2);
void			and_ft(t_battle *battle, int param1, int param2, int *reg);
void			or_ft(t_battle *battle, int param1, int param2, int *reg);

#endif
