/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 12:10:53 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 14:14:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			st(t_battle *reg, int reg, int param, int a)
{
	reg += a;
	str = (uc *)inttochar(&reg);
	setmemory(battle, ret, str, 4);
}
