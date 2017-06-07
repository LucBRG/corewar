/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 12:10:53 by tferrari          #+#    #+#             */
/*   Updated: 2017/06/07 15:23:50 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			st(t_battle *battle, int reg, int param, int a)
{
	reg += a;
	str = (uc *)inttochar(&reg);
	setmemory(battle, ret, str, 4);
}
