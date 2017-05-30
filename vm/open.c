/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:00:54 by dbischof          #+#    #+#             */
/*   Updated: 2017/05/30 14:42:10 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char *open_bot(char *path)
{
	int		fd;
	int		ret;
	char	*buff;

	if ((fd = open(path, O_RDONLY)) != -1)
	{
		buff = strnew(CHAMP_MAX_SIZE);
		if ((ret = read(fd, buff, CHAMP_MAX_SIZE)) == 0)
			return (buff);
		strdel(&buff);
	}
	return (NULL);
}
