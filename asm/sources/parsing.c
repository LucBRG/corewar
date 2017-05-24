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

char 		*give_line(char *str)
{
	int		space;
	int		comment;
	int		str_len;
	int		dst_len;
	char	*dst;

	space = 0;
	comment = cor_strchr(str, '#');
	str_len = ft_strlen(str);
	while (str[space] && ft_is_space(str[space]))
		space++;
	dst_len = (comment != -1) ? (comment - space) : (str_len - space);
	if (dst_len != str_len)
	{
		dst = ft_strnew(dst_len);
		ft_strncpy(dst, &str[space], dst_len);
		return (dst);
	}
	return (ft_strdup(str));
}

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
	{
		env->str[i] = give_line(str);
		i++;
	}
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

static void	parse_header(t_header *header, t_asm *env)
{
	env->i = 0;
	while (env->i < env->nb_line
		&& (!header->prog_name[0] || !header->comment[0]))
	{
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

int		is_in(const char *str, char letter)
{
	while (*str)
	{
		if (*str == letter)
			return (1);
		str++;
	}
	return (0);
}

void		jump_space(t_asm *env)
{
	while (ft_is_space(env->str[env->i][env->j]))
		env->j++;
}

void		find_lab(t_asm *env)
{
	t_arg	*arg;

	env->j = 0;
	while (!ft_is_space(env->str[env->i][env->j]) && env->str[env->i][env->j] != LABEL_CHAR)
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
		//printf("Label |%s|\n", arg->name);
		env->j++;
		jump_space(env);
	}
	else
		env->j = 0;
}

void		find_ins(t_asm *env)
{
	int		i;
	size_t	len;
	t_arg	*arg;

	i = 15;
	while (i >= 0)
	{
		len = ft_strlen((const char*)g_op_tab[i].name);
		if (!ft_strncmp((const char*)g_op_tab[i].name, &env->str[env->i][env->j], len)
			&& ft_is_space(env->str[env->i][env->j + len]))
		{
			//printf("Instruction: %s\n", g_op_tab[i].name);
			arg = arg_create();
			arg->op_code = g_op_tab[i].op_code;
			arg->special |= T_INSTRU;
			arg_add(&env->args, arg);
			env->j += len;
			return ;
		}
		i--;
	}
	show_err(5, env->i);
}

void		find_par(t_asm *env)
{
	t_arg	*arg;
	(void)arg;

	jump_space(env);

	char	**split;
	split = ft_strsplit(&env->str[env->i][env->j], ',');
	while (*split)
	{
		printf("|%s|\n", *split);
		split++;
	}
	printf("\n");
}

void		parse_instruction(t_asm *env)
{
	while (env->i < env->nb_line)
	{
		if (env->str[env->i][0])
		{
			find_lab(env);
			find_ins(env);
			find_par(env);
		}
		env->i++;
	}
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
	parse_instruction(env);

	printf("\n\n");

	t_arg	*lst;
	int 	n;

	lst = env->args;
	n = -1;
	while (lst)
	{
		printf("%d\t", ++n);

		if (lst->name)
		{
			printf(RED"LAB"RESET"\t%s", lst->name);
		}
		else if (lst->op_code)
		{
			printf(CYAN"INS"RESET"\t%s", g_op_tab[lst->op_code - 1].name);
		} 

		printf("\n");
		lst = lst->next;
	}
	return (0);
}
