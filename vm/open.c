/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:00:54 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/31 14:26:35 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define MIN_BOT		4
#define BUFFER		10000
#define NB_MAGIK	(0)
#define NAME		(4)
#define OC_NULL_1	(4 + PROG_NAME_LENGTH)
#define NB_INST		(8 + PROG_NAME_LENGTH)
#define COMMENT		(12 + PROG_NAME_LENGTH)
#define OC_NULL_2	(12 + PROG_NAME_LENGTH + COMMENT_LENGTH)
#define INST		(16 + PROG_NAME_LENGTH + COMMENT_LENGTH)

int		open_bot(char *path, unsigned char **bot)
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

int		checkpoint_valid(unsigned char *bot, int len)
{
	if (chartoint(bot + NB_MAGIK) == COREWAR_EXEC_MAGIC
		&& !chartoint(bot + OC_NULL_1)
		&& !chartoint(bot + OC_NULL_2)
		&& chartoint(bot + NB_INST) == len - INST)
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

t_bot	*creabot(char *path)
{
	int				i;
	int				length;
	t_bot			*bot;
	unsigned char	*bot_brut;

	bot_brut = NULL;
	length = open_bot(path, &bot_brut);
	// debug(bot_brut, length);
	if (!bot_brut || length <= MIN_BOT || !checkpoint_valid(bot_brut, length))
		return (NULL);
	bot = newbot();
	ft_memcpy(bot->name, (bot_brut + NAME), PROG_NAME_LENGTH);
	bot->nb_instructions = chartoint(bot_brut + NB_INST);
	ft_memcpy(bot->comment, (bot_brut + COMMENT), COMMENT_LENGTH);
	bot->instructions = (unsigned char*)malloc(bot->nb_instructions);
	ft_memcpy(bot->instructions, (bot_brut + INST), bot->nb_instructions);
	return (bot);
}
