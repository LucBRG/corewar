/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:58:54 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/02 17:09:37 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_header(t_asm *env, int fd)
{
	int i;
	int	nb;

	i = 3;
	nb = COREWAR_EXEC_MAGIC;
	while (i > 0)
	{
		ft_putstr_fd(ft_base(nb / ft_power(256, i), 16, "0123456789abcdef"), fd);
		nb = nb % ft_power(256, i);
		i--;
	}
	ft_putstr_fd(ft_base(nb % 256, 16, "0123456789abcdef"), fd);
}
/*
void	write_core(t_asm *env, int fd)
{
	t_arg	*lst;

	lst = env->args;
	while (lst)
	{
		if (lst->special & T_INST)
			write_inst(lst, fd);
		else if (lst->special & T_REG)
			write_reg(lst, fd);
		else if (lst->special & T_DIR)
			write_dir(lst, fd);
		else if (lst->special & T_IND)
			write_ind(lst, fd);
		lst = lst->next;
	}
}
*/
void	translate(t_asm *env, char *str)
{
	int		fd;
	char	*name;
	int		len;

	len = ft_strlen(str);
	name = (char*)malloc(sizeof(*name) * (len + 2));
	name = ft_strncpy(name, str, len - 1);
	name  = ft_strcat(name, "cor");
	fd = open(name, O_WRONLY | O_CREAT, 0666);
	write_header(env, fd);
	//write_core(env, fd);
}
