/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:30 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/26 16:11:32 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static void	type_par(char *str, t_asm *env)
{
	t_arg	*arg;

	arg = arg_create();
	arg->name = ft_strdup(str);
	if (str[0] == 'r')
	{
		arg->special |= T_REG;
		arg->octet = 1;
	}
	else if (str[0] == '%')
	{
		arg->special |= T_DIR;
		if (env->oct_line == 1 || env->oct_line == 2 || env->oct_line == 6 ||
			env->oct_line == 7 || env->oct_line == 8 || env->oct_line == 13)
			arg->octet = 4;
		else
			arg->octet = 2;
	}
	else
	{
		arg->special |= T_IND;
		arg->octet = 2;
	}
	verif_name(env, arg);
	arg_add(&env->args, arg);
}

void		find_lab(t_asm *env)
{
	t_arg	*arg;

	env->j = 0;
	while (!ft_is_space(env->str[env->i][env->j]) &&
		env->str[env->i][env->j] != LABEL_CHAR)
	{
		if (!is_in(LABEL_CHARS, env->str[env->i][env->j]))
			show_err(3, env->i);
		env->j++;
	}
	if (env->j && env->str[env->i][env->j] == LABEL_CHAR)
	{
		arg = arg_create();
		arg->name = ft_strnew(env->j);
		arg->special |= T_LAB;
		ft_strncpy(arg->name, &env->str[env->i][0], env->j);
		arg_add(&env->args, arg);
		env->j++;
		jump_space(env);
	}
	else
		env->j = 0;
}

int		find_ins(t_asm *env)
{
	int		i;
	size_t	len;
	t_arg	*arg;

	i = 15;
	while (i >= 0)
	{
		len = ft_strlen((const char*)g_op_tab[i].name);
		if (!ft_strncmp((const char*)g_op_tab[i].name,
			&env->str[env->i][env->j], len)
			&& ft_is_space(env->str[env->i][env->j + len]))
		{
			arg = arg_create();
			arg->op_code = g_op_tab[i].op_code;
			arg->special |= T_INSTRU;
			arg->n_args = g_op_tab[i].n_args;
			arg_add(&env->args, arg);
			env->j += len;
			env->oct_line = g_op_tab[i].op_code;
			return (arg->n_args);
		}
		i--;
	}
	show_err(5, env->i);
	return (0);
}

void		find_par(t_asm *env, unsigned char n_args)
{
	t_arg	*arg;
	char	**split;

	jump_space(env);
	split = ft_strsplit(&env->str[env->i][env->j], ',');
	if (ft_strsplit_len(split) != n_args || split == NULL)
		show_err(8, env->i);
	while (*split)
	{
		type_par(*split, env);
		split++;
	}
	ft_strsplit_free(split);
}
