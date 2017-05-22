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
	(void)env;
	char		str[BUF_SZ];
	header_t	*header;
	int			nu;
	int			i;

	nu = 0;
	header = (header_t*)malloc(sizeof(*header));
	if (header == NULL)
		exit(EXIT_FAILURE);
	init_header(header);
	ft_bzero(str, BUF_SZ);
	while (header->prog_name[0] == '\0' || header->comment[0] == '\0')
	{
		my_fgets(str, BUF_SZ, file);
		if (!str[0]) {
			ft_printf("EXIT\n");
			exit(EXIT_FAILURE);
		}
		nu = corewar_strchr(str, '#');
		if (nu != -1) 
			str[nu] = 0;

		i = 0;
		while (str[i] && ft_is_space(str[i]))
			i++;

		ft_printf("\"%s\"\n", str + i);	
		if (!header->prog_name[0] && !ft_strncmp(str + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			ft_strcpy(header->prog_name, "name");
		}
		else if (!header->comment[0] && !ft_strncmp(str + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		{
			ft_strcpy(header->comment, "comment");
		}
		else
		{
			ft_printf("ERROR\n");
			return (0);
		}
	}
	ft_printf("FIN\n");
	return (0);
}
