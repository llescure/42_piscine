/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:14:08 by thsembel          #+#    #+#             */
/*   Updated: 2020/08/16 18:53:30 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free(int **tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_treat(char *argv)
{
	int **rule;
	int **grid;

	rule = NULL;
	grid = NULL;
	if ((!(rule = ft_init_rule(argv))) ||
			(!(grid = ft_init_grid())))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		if (ft_fill_grid(grid, rule, 0))
			ft_display(grid);
		else
			write(1, "Error\n", 6);
		ft_free(rule);
		ft_free(grid);
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '1' || str[i] > '4') && str[i] != ' ' &&
				str[i + 1] != ' ' && str[i + 1] != '\0')
			return (0);
		else if (str[i] == ' ' && (str[i + 1] < '1' || str[i + 1] > '4'))
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_strlen(argv[1]) != 31 || ft_check_nb(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_treat(argv[1]);
	return (0);
}
