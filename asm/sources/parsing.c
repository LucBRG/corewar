/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:33:53 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/22 12:18:35 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static void	init_header(header_t *header)
{
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
}

int	parsing_asm(t_asm *env, t_file *file)
{
	char		str[BUF_SZ];
	header_t	*header;
	int			nu;
	int			i;

	nu = 0;
	header = (header_t*)malloc(sizeof(header_t*));
	if (header == NULL)
		exit(EXIT_FAILURE);
	init_header(header);
	ft_bzero(str, BUF_SZ);
	while (header->prog_name[0] == '\0' || header->comment[0] == '\0')
	{
		ft_printf("KO\n");
		my_fgets(str, BUF_SZ, file);
		if (!str[0]) {
			ft_printf("EXIT\n");
			exit(EXIT_FAILURE);
		}
		ft_printf("OK\n");
		nu = corewar_strchr(str, '#');
		if (nu != -1) 
			str[nu] = 0;

		ft_printf("\"%s\"\n", str);	
		i = 0;
		while (str[i] && ft_is_space(str[i]))
			i++;

		ft_printf("\"%s\"\n", str + i);	
		if (!header->prog_name[0] && !ft_strncmp(str + i, ".name", 5))
		{
			//ft_strcpy(header->prog_name, "name");
			ft_printf("found .name!\n\n");
		}
		else if (header->comment[0] == 0 && !ft_strncmp(str + i, ".comment", 8))
		{
			//ft_strcpy(header->comment, "comment");
			ft_printf("found .comment!\n\n");
		}
		else
		{
			ft_printf("Au revoir\n");
			return (0);
		}
	}
	ft_printf("FIN\n");
	return (0);
}
