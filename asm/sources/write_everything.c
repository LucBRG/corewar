/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:56:10 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/02 17:00:49 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ocp(t_arg *lst)
{
	:
}

void	write_inst(t_arg *lst, int fd)
{
	int ocp;

	ocp = 0;
	if (lst->ocp == 1)
		ocp = ocp(lst);
}
