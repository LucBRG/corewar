/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:54:47 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/17 14:53:30 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static void	init_struct(t_asm **env)
{
	*env = (t_asm*)malloc(sizeof(t_asm*));
	if (*env == NULL)
		exit(EXIT_FAILURE);
	(*env)->str = NULL;
}

static void	free_struct(t_asm *env)
{
	if (env->str)
		free(env->str);
	free(env);
}

int		main(int ac, char **av)
{
	t_asm	*env;
	t_file	*file;

	if (ac != 2)
	{
		ft_printf("Usage : ./asm [filename.s]\n");
		exit(EXIT_FAILURE);
	}
	file = my_fopen(av[1]);
	if (file->fd == -1 || !ft_strstr(av[1], ".s"))
	{
		ft_printf("File doesn't exist.\n");
		exit(EXIT_FAILURE);
	}
	init_struct(&env);
	parsing_asm(env, file);
	//write_in();
	free_struct(env);
	return (0);
}
