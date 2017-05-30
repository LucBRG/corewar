/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:00:54 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/30 18:55:24 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#define MIN_BOT 4
#define BUFFER 10000

int	open_bot(char *path, unsigned char **bot)
{
	int		fd;
	int		ret;
	char	buff[BUFFER];

	ret = 0;
	ft_bzero(buff, BUFFER);
	if ((fd = open(path, O_RDONLY)) != -1)
		if ((ret = read(fd, buff, BUFFER)) != -1)
		{
			*bot = (unsigned char*)malloc(ret);
			ft_memcpy(*bot, buff, ret);
			return (ret);
		}
	return (ret);
}

int		chartoint(unsigned char *t)
{
	return ((t[0] << 24) | (t[1] << 16) | (t[2] << 8) | t[3]);
}

int		check_magicnumber(unsigned char *bot)
{
	if (chartoint(bot) == COREWAR_EXEC_MAGIC)
		return (1);
	return (0);
}

t_bot	*newbot(void)
{
	t_bot *bot;

	bot = (t_bot*)malloc(sizeof(t_bot));
	bot->name = ft_strnew(PROG_NAME_LENGTH);
	bot->comment = ft_strnew(COMMENT_LENGTH);
	bot->instructions = NULL;
	bot->nb_instructions = 0;
	return (bot);
}

// void	delbot(t_bot **bot)
// {
// 	ft_strdel(bot->name);
// 	ft_strdel(bot->comment);
// 	free(*bot);
// }

t_bot	*creabot(char *path)
{
	int				i;
	int				length;
	t_bot			*bot;
	unsigned char	*bot_brut;

	bot_brut = NULL;
	length = open_bot(path, &bot_brut);
	debug(bot_brut, length);
	if (!bot_brut || length <= MIN_BOT || !check_magicnumber(bot_brut))
		return (NULL);
	bot = newbot();
	i = 4;
	ft_memcpy(bot->name, (bot_brut + i), PROG_NAME_LENGTH);
	i += PROG_NAME_LENGTH + 4;
	bot->nb_instructions = chartoint(bot_brut + i);
	i += 4;
	ft_memcpy(bot->comment, (bot_brut + i), COMMENT_LENGTH);
	i += COMMENT_LENGTH + 4;
	bot->instructions = (char*)malloc(bot->nb_instructions);
	ft_memcpy(bot->instructions, (bot_brut + i), bot->nb_instructions);
	displaybot(bot);
	return (bot);
}
