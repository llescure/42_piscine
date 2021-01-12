/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:03:02 by llescure          #+#    #+#             */
/*   Updated: 2020/08/08 19:39:25 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_ponct(void);
void	ft_put_char(char a, char b, char c);
char g_s;
char g_c;

void	ft_print_comb(void)
{
	char x;
	char y;
	char z;

	x = '0';
	y = '0';
	z = '0';
	while (x <= '7')
	{
		y = x + 1;
		while (y <= '8')
		{
			z = y + 1;
			while (z <= '9')
			{
				ft_put_char(x, y, z);
				if (x != '7')
					ft_print_ponct();
				z++;
			}
			y++;
		}
		x++;
	}
}

void	ft_put_char(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_ponct(void)
{
	g_s = ' ';
	g_c = ',';
	write(1, &g_c, 1);
	write(1, &g_s, 1);
}
