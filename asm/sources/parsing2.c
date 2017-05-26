/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:42 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/26 16:11:43 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

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
	int	n_args;

	while (env->i < env->nb_line)
	{
		env->oct_line = 0;
		if (env->str[env->i][0])
		{
			find_lab(env);
			n_args = find_ins(env);
			find_par(env, n_args);
		}
		env->i++;
	}
}
