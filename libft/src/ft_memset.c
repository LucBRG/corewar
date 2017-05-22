/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:06:57 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/07 16:31:51 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*b_copy;
	char	c_copy;

	i = 0;
	b_copy = (char *)b;
	c_copy = (unsigned char)c;
	while (i < len)
	{
		b_copy[i] = c_copy;
		i++;
	}
	return (b);
}
