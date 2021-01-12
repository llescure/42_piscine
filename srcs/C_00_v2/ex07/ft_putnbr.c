/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:05:30 by llescure          #+#    #+#             */
/*   Updated: 2020/08/08 17:32:52 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
char	ft_is_negative(long n);

void	ft_putnbr(int nb)
{
	long major;

	major = nb;
	if (ft_is_negative(major) == 'N')
	{
		major = major * -1;
	}
	if (major >= 0 && major <= 9)
	{
		ft_putchar(major + 48);
	}
	else
	{
		ft_putnbr(major / 10);
		ft_putnbr(major % 10);
	}
}

char	ft_is_negative(long n)
{
	if (n >= 0)
		return ('P');
	else
		ft_putchar('-');
	return ('N');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
