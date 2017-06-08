#include "asm.h"

int		tot_oct_instru(t_arg *lst)
{
	while (!(lst->special & T_INSTRU))
		lst = lst->prec;
	return (lst->tot_octets);
}

int		label_apres(t_arg *find, t_arg *lst)
{
	int				oct;
	int				tmp;

	oct = 0;
	while (find && ft_strcmp(find->name, &(lst->name[1])) != 0)
	{
		tmp = tot_oct_instru(lst);
		if (find->special & T_INSTRU)
			oct += find->tot_octets;
		find = find->next;
	}
	oct += tmp;
	printf("nb = %d\n", oct);
	return (oct);
}

int		label_avant(t_arg *find, t_arg *lst, int i, int line)
{
	int				oct;
	int				tmp;

	oct = 0;
	find = find->next;
	while (find && ft_strcmp(find->name, &(lst->name[1])) != 0 && i != line)
	{
		tmp = tot_oct_instru(lst);
		if (find->special & T_INSTRU)
		{
			printf("tot_octet line = %d\n", find->tot_octets);
			oct += find->tot_octets;
			i++;
		}
		find = find->next;
	}
	oct -= tmp;
	printf("\tnb = %d\n", -oct);
	return (-oct);
}

void	write_translation(unsigned int nb, int oct, int fd)
{
	int				i;
	unsigned char	c;

	i = oct - 1;

	while (i > 0)
	{
		c = nb / ft_power(256, i);
		nb = nb % ft_power(256, i);
		write(fd, &c, 1);
		i--;
	}
	c = nb % ft_power(256, i);
	write(fd, &c, 1);
}
