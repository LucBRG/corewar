/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:01:20 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/22 11:14:07 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"

typedef	struct		s_arg
{
	char			*name;
	int				op_code;
	int				special;
	int				ocp;
	struct s_arg	*ref;
	struct s_arg	*next;
	struct s_arg	*prec;
}					t_arg;

typedef	struct		s_asm
{
	int				nb_line;
	char			**str;
	int				i;
	struct s_arg	*args;
}					t_asm;

int					cor_strchr(const char *s, int c);
int					parsing_asm(t_asm *env, t_file *file);
void				show_err(int id, int line);

t_arg				*arg_create(void);
void				arg_delete(t_arg **head);
void				arg_add(t_arg **head, t_arg *arg);

#endif
