/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:00:28 by llescure          #+#    #+#             */
/*   Updated: 2020/08/27 11:51:09 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	ft_first_word(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]) == 0)
		{
			while (str[i] != '\0')
			{	
				if (ft_is_space(str[i]) == 1)
					return;
				ft_putchar(str[i]);
				i++;
			}
		}
		i++;
	}
}

	int		main(void)
	{
		ft_first_word("         B onjour");
	}
