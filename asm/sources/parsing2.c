/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:42 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/30 16:32:25 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

int	verif_exist(t_arg *lst, char *str)
{
	while (lst)
	{
		if ((lst->special & T_LAB) &&
			ft_strncmp(lst->name, &(str[1]), cor_strlen(lst->name)) == 0)
			return (1);
		lst = lst->next;
	}
	show_err(4, 0);
	return (0);
}

void		label_exist(t_asm *env)
{
	t_arg	*lst;
	t_arg	*tmp;
	int		line;

	line = env->header_len;
	lst = env->args;
	tmp = env->args;
	while (lst)
	{
		if (!(lst->special & T_LAB) && ft_strchr(lst->name, LABEL_CHAR))
			verif_exist(tmp, lst->name);
		lst = lst->next;
	}
}

void		copy_header(char *dst, t_asm *env, int i)
{
	int	j;

	j = 0;
	while (ft_is_space(env->str[env->i][i]))
		i++;
	if (env->str[env->i][i] != '"')
		show_err(3, env->i);
	i++;
	while (env->str[env->i][i] != '"')
		dst[j++] = env->str[env->i][i++];
	i++;
	while (ft_is_space(env->str[env->i][i]))
		i++;
	if (env->str[env->i][i])
		show_err(3, env->i);
}

void		parse_instruction(t_asm *env)
{
	int		n_args;
	t_arg	ref_inst;

	while (env->i < env->nb_line)
	{
		env->oct_line = 0;
		ref_inst.tot_octets = 1;
		if (env->str[env->i][0])
		{
			find_lab(env);
			if ((n_args = find_ins(env, &ref_inst)) != 0)
				find_par(env, n_args, &ref_inst);
		}
		env->i++;
	}
}
