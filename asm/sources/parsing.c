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

static void	init_parse(header_t *header, t_asm *env)
{
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
	env->nb_line = 0;
}

static void	fill_parsing(t_asm *env, t_file *file)
{
	int		i;
	char	str[BUF_SZ];

	i = 0;
	while (my_fgets(str, BUF_SZ, file))
		env->nb_line++;
	lseek(file->fd, 0, SEEK_SET);
	env->str = (char**)malloc(sizeof(char*) * env->nb_line);
	while (my_fgets(str, BUF_SZ, file))
		env->str[i++] = ft_strdup(str);
	
}
/*
	.name ""valid name"
	.comment "valid comment"
*/
static void	copy_header(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != '"')
		i++;
	i++;
	while (src[i] != '"')
		dst[j++] = src[i++];
}

static void	parse_header(header_t *header, t_asm *env)
{
	int	i;
	int	nu;
	int	space;

	i = 0;
	while (!header->prog_name[0] || !header->comment[0])
	{
		nu = corewar_strchr(env->str[i], '#');
		if (nu != -1) 
			env->str[nu] = 0;
		space = 0;
		while (env->str[i][space] && ft_is_space(env->str[i][space]))
			space++;
		if (!env->str[i][space])
			;
		else if (!header->prog_name[0] && !ft_strncmp(env->str[i] + space, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			copy_header(header->prog_name, env->str[i]);
		else if (!header->comment[0] && !ft_strncmp(env->str[i] + space, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			copy_header(header->comment, env->str[i]);
		else
			show_err(3, 0);
		i++;
	}
}

int	parsing_asm(t_asm *env, t_file *file)
{
	char		str[BUF_SZ];
	header_t	*header;

	header = (header_t*)malloc(sizeof(*header));
	if (header == NULL)
		exit(EXIT_FAILURE);
	init_parse(header, env);
	ft_bzero(str, BUF_SZ);
	fill_parsing(env, file);
	if (!env->str)
	{
		ft_printf("error \n");
		exit(EXIT_FAILURE);
	}
	parse_header(header, env);
	ft_printf("name = %s\ncomment = %s\n", header->prog_name, header->comment);
	//parse_instruction(env);
	return (0);
}
