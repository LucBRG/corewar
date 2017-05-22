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

typedef	struct	s_asm
{
	char	*str;
}				t_asm;

typedef struct	s_parse
{
	int		name;
	int		comment;
}				t_parse;

int	parsing_asm(t_asm *env, t_file *file);

#endif
