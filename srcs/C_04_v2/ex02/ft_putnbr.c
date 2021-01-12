/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:09:05 by llescure          #+#    #+#             */
/*   Updated: 2020/08/17 10:56:59 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	ft_putnbr(int nb)
{
	long reslt;

	reslt = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		reslt = reslt * -1;
	}
	if (reslt >= 0 && reslt <= 9)
		ft_putchar(reslt + 48);
	else
	{
		ft_putnbr(reslt / 10);
		ft_putnbr(reslt % 10);
	}
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}
