#include "asm.h"

void	good_order(t_asm *env)
{
	t_arg				*lst;
	t_arg				*tmp;
	unsigned char		i;

	lst = env->args;
	while (lst)
	{
		if (lst->special & T_INSTRU)
		{
			i = 0;
			tmp = lst;
			tmp = tmp->next;
			while (i < g_op_tab[lst->op_code - 1].n_args)
			{
				if (!(tmp->special & g_op_tab[lst->op_code - 1].args[i]))
					show_err(3, 0);
				tmp = tmp->next;
				i++;
			}
		}
		lst = lst->next;
	}
}