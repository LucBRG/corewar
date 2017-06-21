
#include "vm.h"

int	main(int ac, char **av)
{
	int			i;
	t_process	*win;
	t_battle	*b;

	i = -1;
	if (!(b = initbattle(ac, av)))
		return (0);
	printf("FIGHT\t%d\n", b->bots.nb);
	print_memory(b);
	if (b->bots.nb)
	{
		ft_lstiter(b->process, displayprocess);
		win = battle_launch(b);
		if (win)
			printf("le joueur %d(%s) a gagne\n", win->bot->id, win->bot->name);
	}
	print_memory(b);
	ft_printf("\n");
	displayprocess(b->process);
	// ft_printf("\nreg 3 = %u", b->cur_process->registre[3]);
	return (0);
}
