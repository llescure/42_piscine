/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:59:52 by llescure          #+#    #+#             */
/*   Updated: 2020/08/27 17:16:09 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_double(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *str, char *str2)
{
	int i;
	int j;
	int compt;

	i = 1;
	j = 0;
	compt = 1;
	ft_putchar(str[0]);
	while (str[i] != '\0')
	{
		if (str[i] != str[i - compt])
		{
			ft_putchar(str[i]);
			compt++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
			{
				break ;
			}
			j++;
		}
		i++;
	}
}
