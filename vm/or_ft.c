/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:14:27 by tferrari          #+#    #+#             */
/*   Updated: 2017/05/31 12:14:51 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_battle.h"

void			or_ft(t_battle *battle, int param1, int param2, int *reg)
{
	char a;
	char b;

	a = param1;
	b = param2;

	*reg = a | b;
}
