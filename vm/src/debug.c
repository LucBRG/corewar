
#include "vm.h"

enum{C_BLACK, C_RED, C_GREEN, C_YELLOW, C_BLUE, C_PURPLE, C_CYAN, C_GREY};

void	hexa(uc *s, int len, int color)
{
	int i;

	i = -1;
	while (++i < len)
		ft_printf("\033[4%d;%dm%.2x \033[40;0m", color, (color) ? 30 : 0, s[i]);
}

void	debug(uc *s, int len)
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
	ft_printf("\n");
}

void	displaybot(t_bot *bot)
{
	ft_printf("id\t\t: %d\nlive\t\t: %d\nname\t\t: %s\ncomment\t\t: %s\ninstructions\t: %d\n",
		bot->id, bot->live, bot->name, bot->comment, bot->nb_instructions);
	hexa(bot->instructions, bot->nb_instructions, bot->id % 6);
	ft_printf("\n");
}

void	displayprocess(t_list *elem)
{
	int color;
	t_process *process;

	if (!elem)
	{
		ft_printf("no elem\n");
		return ;
	}
	process = (t_process*)elem->content;
	color = process->bot->id % 6;
	ft_printf("\033[3%dm", color);
	ft_printf("%p\npc\t: %d\n", process, process->pc);
	hexa((uc*)process->registre, REG_NUMBER * REG_SIZE, color);
	ft_printf("\n");
	ft_printf("\033[3%dm", color);
	displaybot(process->bot);
	ft_printf("\033[40;0m");
}