/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:24:50 by llescure          #+#    #+#             */
/*   Updated: 2020/08/08 17:19:02 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);
void	ft_putnbr(int nb);

int g_a;
int g_b;

void	ft_print_comb2(void)
{
	g_a = 0;
	while (g_a < 99)
	{
		g_b = g_a + 1;
		while (g_b < 100)
		{
			if (g_a <= 9)
				ft_putchar('0');
			ft_putnbr(g_a);
			ft_putchar(' ');
			if (g_b <= 9)
				ft_putchar('0');
			ft_putnbr(g_b);
			if (g_a == 98)
				break ;
			ft_putchar(',');
			ft_putchar(' ');
			g_b++;
		}
		g_a++;
	}
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
