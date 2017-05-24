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

static void	init_parse(t_header *header, t_asm *env)
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
	if (!env->str)
		show_err(0, -1);
	while (my_fgets(str, BUF_SZ, file))
		env->str[i++] = ft_strdup(str);
}

static void	copy_header(char *dst, t_asm *env, int i)
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

char 		*give_line(t_asm *env)
{
	int		space;
	int		comment;
	int		str_len;
	int		dst_len;
	char	*dst;

	space = 0;
	comment = cor_strchr(env->str[env->i], '#');
	str_len = ft_strlen(env->str[env->i]);
	while (env->str[env->i][space] && ft_is_space(env->str[env->i][space]))
		space++;
	dst_len = (comment != -1) ? (comment - space) : (str_len - space);
	if (dst_len != str_len)
	{
		dst = ft_strnew(dst_len);
		ft_strncpy(dst, &env->str[env->i][space], dst_len);
		free(env->str[env->i]);
		return (dst);
	}
	return (env->str[env->i]);
}

static void	parse_header(t_header *header, t_asm *env)
{
	env->i = 0;
	while (env->i < env->nb_line
		&& (!header->prog_name[0] || !header->comment[0]))
	{
		env->str[env->i] = give_line(env);
		if (!env->str[env->i][0])
			;
		else if (!header->prog_name[0] && !ft_strncmp(env->str[env->i],
			NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			copy_header(header->prog_name, env,
				ft_strlen(NAME_CMD_STRING));
		else if (!header->comment[0] && !ft_strncmp(env->str[env->i],
			COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			copy_header(header->comment, env,
				ft_strlen(COMMENT_CMD_STRING));
		else
			show_err(3, env->i);
		env->i++;
	}
	if (!header->prog_name[0] || !header->comment[0])
		show_err(3, -1);
}

void		parse_instruction(t_asm *env)
{
	(void)env;
	return ;
}

int			parsing_asm(t_asm *env, t_file *file)
{
	char		str[BUF_SZ];
	t_header	*header;

	header = (t_header*)malloc(sizeof(*header));
	if (header == NULL)
		exit(EXIT_FAILURE);
	init_parse(header, env);
	ft_bzero(str, BUF_SZ);
	fill_parsing(env, file);
	parse_header(header, env);
	ft_printf("\n|DEBUG|\n================================\nName:\t\t|%s|\nComment:\t|%s|\n",
		header->prog_name, header->comment);
	parse_instruction(env);
	return (0);
}
