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

static char	ocp_f(t_arg *lst)
{
	int		i;
	unsigned char	c;
	int		op_code;

	i = 0;
	c = 0;
	op_code = lst->op_code;
	lst = lst->next;
	while (i++ < g_op_tab[op_code - 1].n_args)
	{
		if (lst->special & T_REG)
			c |= 1;
		else if (lst->special & T_DIR)
			c |= 2;
		else if (lst->special & T_IND)
			c |= 3;
		c <<= 2;
		lst = lst->next;
	}
	while (i++ < 4)
		c <<= 2;
	return (c);
}

void	write_inst(t_arg *lst, int fd)
{
	char ocp;

	ocp = 0;
	if (g_op_tab[lst->op_code - 1].has_ocp)
		ocp = ocp_f(lst);
	ft_putchar_fd(lst->op_code, fd);
	if (g_op_tab[lst->op_code - 1].has_ocp)
		ft_putchar_fd(ocp, fd);
}