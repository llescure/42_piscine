/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:45:24 by llescure          #+#    #+#             */
/*   Updated: 2020/08/26 22:03:07 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wspace(char str);
int		ft_strlen(char *str);

int		ft_atoi(char *str)
{
	unsigned int	i;
	int				reslt;
	int				nega;

	i = 0;
	nega = 1;
	reslt = 0;
	while (ft_wspace(str[i]) == 1 || str[i] == '-' || str[i] == '+' ||
		(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			nega = nega * -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			reslt = reslt * 10 + (str[i] - '0');
		}
		if (reslt != 0 && (str[i + 1] == '-' || str[i + 1] == '+' ||
			ft_wspace(str[i + 1]) == 1))
			break ;
		i++;
	}
	reslt = reslt * nega;
	return (reslt);
}

int		ft_wspace(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' || str == '\f' ||
		str == '\r' || str == ' ')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
