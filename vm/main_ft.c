/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:08:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/31 12:06:41 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_battle.h"

int main(void)
{
	t_battle battle;
	int i = 0;

	ft_bzero(&battle, sizeof(battle));
	battle.cur_men = 28;
	and_ft(&battle, 255, 107, &i);
	ft_printf("reg = %s\n", ft_itoa_base(i, 16));
	// while (i < 30)
	// {
	// 	printf("line %d = %c\n", i, battle.memory[i]);
	// 	i++;
	// }
	return (0);
}
