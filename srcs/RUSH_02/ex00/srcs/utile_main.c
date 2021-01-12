/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:17:50 by jbondri           #+#    #+#             */
/*   Updated: 2020/08/23 22:31:38 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "utile.h"
#include "dictionary.h"

char	*refine(char *str)
{
	int		i;
	int		buff;

	i = 0;
	while (str[i] == '0')
		i++;
	buff = i;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			str[0] = '\0';
			return (str);
		}
		i++;
	}
	return (str + buff);
}

void	error(int stat)
{
	if (stat == BASIC)
		ft_putstr("Error\n");
	if (stat == DICT)
		ft_putstr("Dict Error\n");
	return ;
}
