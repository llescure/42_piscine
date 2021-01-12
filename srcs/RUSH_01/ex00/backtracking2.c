/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:40:44 by thsembel          #+#    #+#             */
/*   Updated: 2020/08/16 10:13:51 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[j][i] + 48);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_check_rule(int **grid, int **rule, int x, int y)
{
	if (ft_check_right(grid, rule, y) && ft_check_left(grid, rule, y)
			&& ft_check_up(grid, rule, x) &&
			ft_check_down(grid, rule, y))
		return (1);
	return (0);
}

int		ft_fill_grid(int **grid, int **rule, int pos)
{
	int x;
	int y;
	int s;

	x = pos / 4;
	y = pos % 4;
	s = 1;
	if (pos == 16)
		return (1);
	while (s <= 4)
	{
		if (ft_is_twice(grid, y, x, s))
		{
			grid[x][y] = s;
			if (ft_check_rule(grid, rule, x, y))
				if (ft_fill_grid(grid, rule, pos + 1))
					return (1);
		}
		s++;
	}
	grid[x][y] = 0;
	return (0);
}
