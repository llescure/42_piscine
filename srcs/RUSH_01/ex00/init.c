/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:21:40 by thsembel          #+#    #+#             */
/*   Updated: 2020/08/16 10:15:15 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**ft_init_grid(void)
{
	int	i;
	int j;
	int **grid;

	grid = NULL;
	if ((grid = malloc(sizeof(int *) * 4)) == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if ((grid[i] = malloc(sizeof(int) * 4)) == NULL)
			return (NULL);
		j = -1;
		while (++j < 4)
			grid[i][j] = 0;
		i++;
	}
	return (grid);
}

int		**ft_fill_rule(int **rule, char *str, int i)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		if ((rule[x] = malloc(sizeof(int) * 4)) == NULL)
			return (NULL);
		y = 0;
		while (y < 4)
		{
			while (str[i] && y < 4)
			{
				if (str[i] != ' ')
				{
					rule[x][y] = str[i] - '0';
					y++;
				}
				i++;
			}
		}
		x++;
	}
	return (rule);
}

int		**ft_init_rule(char *str)
{
	int i;
	int **rule;

	rule = NULL;
	i = 0;
	if ((rule = malloc(sizeof(int *) * 4)) == NULL)
		return (NULL);
	if ((rule = ft_fill_rule(rule, str, i)) == NULL)
		return (NULL);
	return (rule);
}
