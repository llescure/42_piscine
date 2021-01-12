/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:35:31 by llescure          #+#    #+#             */
/*   Updated: 2020/08/17 21:54:15 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	(void)argc;
	while (argv[0][i] != '\0')
	{
		ft_putchar(argv[0][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}
