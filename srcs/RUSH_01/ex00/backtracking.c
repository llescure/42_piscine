/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:50:09 by thsembel          #+#    #+#             */
/*   Updated: 2020/08/15 19:08:34 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_left(int **grid, int **rule, int y)
{
	int valu;
	int count;
	int x;

	x = 0;
	count = 0;
	valu = 0;
	while (x < 4)
	{
		if (grid[x][y] == 0)
			return (1);
		if (valu < grid[x][y])
		{
			valu = grid[x][y];
			count++;
		}
		x++;
	}
	if (count == rule[2][y])
		return (1);
	return (0);
}

int		ft_check_right(int **grid, int **rule, int y)
{
	int valu;
	int count;
	int x;

	x = 3;
	valu = 0;
	count = 0;
	while (x >= 0)
	{
		if (grid[x][y] == 0)
			return (1);
		if (valu < grid[x][y])
		{
			valu = grid[x][y];
			count++;
		}
		x--;
	}
	if (count == rule[3][y])
		return (1);
	return (0);
}

int		ft_check_down(int **grid, int **rule, int x)
{
	int valu;
	int count;
	int y;

	y = 3;
	valu = 0;
	count = 0;
	while (y >= 0)
	{
		if (grid[x][y] == 0)
			return (1);
		if (grid[x][y] > valu)
		{
			valu = grid[x][y];
			count++;
		}
		y--;
	}
	if (count == rule[1][x])
		return (1);
	return (0);
}

int		ft_check_up(int **grid, int **rule, int x)
{
	int valu;
	int count;
	int y;

	y = 0;
	valu = 0;
	count = 0;
	while (y < 4)
	{
		if (grid[x][y] == 0)
			return (1);
		if (grid[x][y] > valu)
		{
			valu = grid[x][y];
			count++;
		}
		y++;
	}
	if (count == rule[0][x])
		return (1);
	return (0);
}

int		ft_is_twice(int **grid, int y, int x, int s)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
		if (grid[i][y] == s)
			return (0);
	j = -1;
	while (++j < 4)
		if (grid[x][j] == s)
			return (0);
	return (1);
}
