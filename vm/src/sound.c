
#include "vm.h"

void	sound(t_battle *battle)
{
	pid_t		id;
	int			tmp;
	static char	*tab[] = {
						"/usr/bin/afplay",
						"/Users/tferrari/Documents/Corewar/vm/sound/0437.mp3",
						NULL
	};

	id = fork();
	if (id <= 0)
		execve(tab[0], tab, battle->env);
	else
		waitpid(0, &tmp, WUNTRACED | WCONTINUED);
}
