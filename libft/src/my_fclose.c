/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:47:38 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 15:29:30 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_fclose(t_file *file)
{
	if (file->fd != 0)
		if (close(file->fd) == -1)
			return (-1);
	free(file);
	return (0);
}