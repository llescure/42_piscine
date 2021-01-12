/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 10:35:07 by llescure          #+#    #+#             */
/*   Updated: 2020/08/27 15:36:15 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_error(char *base);
int		ft_strlen(char *str);
int		ft_find_cara(char a, char *base);

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int rslt;
	int nega;

	if (ft_error(base) == 0)
		return (0);
	i = 0;
	nega = 1;
	rslt = 0;
	while (str[i] == '+' || str[i] == '-' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r' ||
			str[i] == ' ' || ft_find_cara(str[i], base) != -1)
	{
		if (str[i] == '-')
			nega = nega * -1;
		if (ft_find_cara(str[i], base) != -1)
			rslt = rslt * ft_strlen(base) + ft_find_cara(str[i], base);
		i++;
	}
	return (rslt * nega);
}

int		ft_error(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_find_cara(char a, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

#include <stdio.h>
int		main(void)
{
	char b[] = "01";
	char test[] = "+--11111";
	//ft_atoi_base(test, b);
	printf("%i\n", ft_atoi_base(test, b));
}
