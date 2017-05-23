/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:33:53 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/22 12:18:35 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

int	cor_strchr(const char *s, int c)
{
	int		i;
	int		is_quote;

	i = 0;
	is_quote = 0;
	while (s[i])
	{
		if (s[i] == '"')
			is_quote = !is_quote;
		if (s[i] == c && !is_quote)
			return (i);
		i++;
	}
	return (-1);
}