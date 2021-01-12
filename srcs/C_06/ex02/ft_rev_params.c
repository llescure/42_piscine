/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:43:01 by llescure          #+#    #+#             */
/*   Updated: 2020/08/18 12:19:46 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = argc - 1;
	while (i != 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}
