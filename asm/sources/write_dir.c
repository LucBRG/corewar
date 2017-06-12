#include "asm.h"

void	label2(t_arg *lst, int fd, int line, t_asm *env)
{
	int				i;
	unsigned int	oct;
	t_arg			*find;

	i = 0;
	oct = 0;
	find = env->args;
	while (find)
	{
		if (find->special & T_INSTRU)
			i++;
		else
		{
			if (find && i == line &&
				ft_strcmp(&(find->name[1]), &(lst->name[1])) == 0 &&
				!(find->special & T_LAB))
			{
				oct = label_apres(find,lst);
				break;
			}
			else if (find && ft_strcmp(find->name, &(lst->name[1])) == 0 &&
				(find->special & T_LAB))
			{
				oct = label_avant(find, lst, i, line);
				break ;
			}
		}
		find = find->next;
	}
	write_translation(oct, 2, fd);
}

void	label4(t_arg *lst, int fd, int line, t_asm *env)
{
	int				i;
	unsigned int	oct;
	t_arg			*find;

	i = 0;
	oct = 0;
	find = env->args;
	while (find)
	{
		if (find->special & T_INSTRU)
			i++;
		else
		{
			if (find && i == line &&
				ft_strcmp(&(find->name[1]), &(lst->name[1])) == 0 &&
				!(find->special & T_LAB))
			{
				oct = label_apres(find,lst);
				break;
			}
			else if (find && ft_strcmp(find->name, &(lst->name[1])) == 0 &&
				(find->special & T_LAB))
			{
				oct = label_avant(find, lst, i, line);
				break ;
			}
		}
		find = find->next;
	}
	write_translation(oct, 4, fd);
}

void	on_4oct(t_arg *lst, int fd, int line, t_asm *env)
{
	unsigned int	nb;

	if (lst->name[0] == ':')
		label4(lst, fd, line, env);
	else
	{
		nb = ft_atoi(lst->name);
		write_translation(nb, 4, fd);
	}
}

void	on_2oct(t_arg *lst, int fd, int line, t_asm *env)
{
	unsigned int	nb;

	if (lst->name[0] == ':')
		label2(lst, fd, line, env);
	else
	{
		nb = ft_atoi(lst->name);
		write_translation(nb, 2, fd);
	}
}

void	write_dir(t_arg *lst, int fd, int line, t_asm *env)
{
	if (lst->octet == 4)
		on_4oct(lst, fd, line, env);
	else
		on_2oct(lst, fd, line, env);
}
