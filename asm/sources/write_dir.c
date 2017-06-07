#include "asm.h"

void	label2(t_arg *lst, int fd, int line, t_asm *env)
{
	int				i;
	unsigned int	oct;
	t_arg			*find;
	unsigned char	c;
	int				tmp;

	i = 0;
	oct = 0;
	find = env->args;
	tmp = 0;
	while (find)
	{
		if (find->special & T_INSTRU)
			i++;
		if (i == line && ft_strcmp(find->name, lst->name) == 0)
		{
			while (ft_strcmp(find->name, lst->name) != 0 && find)
			{
				if (find->special & T_INSTRU)
				{
					tmp = find->tot_octets;
					oct += find->tot_octets;
				}
				find = find->next;
			}
			oct -= tmp;
		}
		if (ft_strcmp(find->name, &(lst->name[1])) == 0 && (find->special & T_LAB))
		{
			while (ft_strcmp(find->name, lst->name) != 0 && i != line && find)
			{
				if (find->special & T_INSTRU)
				{
					tmp = find->tot_octets;
					oct += find->tot_octets;
				}
				find = find->next;
			}
			oct -= tmp;
			oct = -oct;
		}
		find = find->next;
	}
	i = 1;
	while (i > 0)
		{
			c = oct / ft_power(256, i);
			oct = oct % ft_power(256, i);
			write(fd, &c, 1);
			i--;
		}
		c = oct % ft_power(256, i);
		write(fd, &c, 1);
}

void	label4(t_arg *lst, int fd, int line, t_asm *env)
{
	int				i;
	unsigned int	oct;
	t_arg			*find;
	unsigned char	c;
	int				tmp;

	i = 0;
	oct = 0;
	find = env->args;
	tmp = 0;
	while (find)
	{
		if (find->special & T_INSTRU)
			i++;
		if (i == line && ft_strcmp(find->name, lst->name) == 0)
		{
			while (ft_strcmp(find->name, lst->name) != 0 && find)
			{
				if (find->special & T_INSTRU)
				{
					tmp = find->tot_octets;
					oct += find->tot_octets;
				}
				find = find->next;
			}
			oct -= tmp;
		}
		if (ft_strcmp(find->name, &(lst->name[1])) == 0 && (find->special & T_LAB))
		{
			while (ft_strcmp(find->name, lst->name) != 0 && i != line && find)
			{
				if (find->special & T_INSTRU)
				{
					tmp = find->tot_octets;
					oct += find->tot_octets;
				}
				find = find->next;
			}
			oct -= tmp;
			oct = -oct;
		}
		find = find->next;
	}
	i = 3;
	while (i > 0)
		{
			c = oct / ft_power(256, i);
			oct = oct % ft_power(256, i);
			write(fd, &c, 1);
			i--;
		}
		c = oct % ft_power(256, i);
		write(fd, &c, 1);
}

void	on_4oct(t_arg *lst, int fd, int line, t_asm *env)
{
	unsigned char	c;
	int				i;
	unsigned int	nb;

	i = 0;
	if (lst->name[0] == ':')
		label4(lst, fd, line, env);
	else
	{
		i = 3;
		nb = ft_atoi(lst->name);
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
}

void	on_2oct(t_arg *lst, int fd, int line, t_asm *env)
{
	unsigned char	c;
	int				i;
	unsigned short	nb;

	i = 0;
	if (lst->name[0] == ':')
		label2(lst, fd, line, env);
	else
	{
		i = 1;
		nb = ft_atoi(lst->name);
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
}

void	write_dir(t_arg *lst, int fd, int line, t_asm *env)
{
	if (lst->octet == 4)
		on_4oct(lst, fd, line, env);
	else
		on_2oct(lst, fd, line, env);
}
