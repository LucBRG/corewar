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

static void	free_struct(t_asm *env)
{
	if (env->str)
		free(env->str);
	free(env);
}

void	show_err(int id, int line)
{
	if (!id)
		ft_putstr_fd("Malloc error.\n", 2);
	else if (id == 1)
		ft_putstr_fd("Usage : ./asm [filename.s]\n", 2);
	else if (id == 2)
		ft_putstr_fd("File doesn't exist.\n", 2);
	else if (id == 3)
	{
		ft_putstr_fd("Syntax error: line ", 2);
		ft_putnbr_fd(line + 1, 2);
		ft_putendl_fd(".", 2);
	}
	else if (id == 4)
	{
		ft_putstr_fd("Label doesn't exist: line ", 2);
		ft_putnbr_fd(line + 1, 2);
		ft_putendl_fd(".", 2);
	}
	else if (id == 5)
	{
		ft_putstr_fd("Bad arguments: line ", 2);
		ft_putnbr_fd(line + 1, 2);
		ft_putendl_fd(".", 2);
	}
	else if (id == 6)
		ft_putstr_fd("Need .name and .comment attribute.\n", 2);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_asm	*env;
	t_file	*file;

	if (ac != 2)
		show_err(1, 0);
	file = my_fopen(av[1]);
	if (file->fd == -1 || !ft_strstr(av[1], ".s"))
		show_err(2, 0);	
	env = (t_asm*)malloc(sizeof(t_asm));
	if (env == NULL)
		exit(EXIT_FAILURE);
	env->str = NULL;
	parsing_asm(env, file);
	//write_in();
	free_struct(env);
	return (0);
}
