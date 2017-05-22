/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:13:27 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/05 10:28:19 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	t;
	int		l;
	int		i;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (i++ < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}
