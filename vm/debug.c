/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:22:36 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/31 14:12:08 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

enum{C_BLACK, C_RED, C_GREEN, C_YELLOW, C_BLUE, C_PURPLE, C_CYAN, C_GREY};

void	hexa(unsigned char *s, int len, int color)
{
	int i;

	i = -1;
	while (++i < len)
		printf("\033[4%d;%dm%.2x \033[40;0m", color, (color) ? 30 : 0, s[i]);
}

void	debug(unsigned char *s, int len)
{
	int i;

	hexa(s, 4, C_RED);
	i = 4;
	hexa(s + i, PROG_NAME_LENGTH, C_BLUE);
	i += PROG_NAME_LENGTH;
	hexa(s + i, 4, C_PURPLE);
	i += 4;
	hexa(s + i, 4, C_YELLOW);
	i += 4;
	hexa(s + i, COMMENT_LENGTH, C_GREEN);
	i += COMMENT_LENGTH;
	hexa(s + i, 4, C_PURPLE);
	i += 4;
	hexa(s + i, len - i, C_CYAN);
	printf("\n");
}

void	displaybot(t_bot *bot)
{
	if (!bot)
		printf("error bot\n");
	else
	{
		printf("name\t\t: %s\ncomment\t\t: %s\ninstructions\t: %d\n",
			bot->name, bot->comment, bot->nb_instructions);
		hexa(bot->instructions, bot->nb_instructions, 0);
	}
}
