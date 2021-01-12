/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:30:37 by llescure          #+#    #+#             */
/*   Updated: 2020/08/23 21:27:30 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utile.h"
#include "main.h"
#include "dictionary.h"
#include <stdio.h>

int		is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}

int		is_number(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int		check_line(char *str)
{
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (is_number(str[i]))
		i++;
	if (str[i] != ' ' && str[i] != ':')
		return (-1);
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (-1);
	i++;
	while (is_printable(str[i]))
		i++;
	if (str[i] != '\0')
		return (-1);
	return (0);
}

char	**line_by_line(char *str)
{
	int		i;
	char	*key;
	char	*value;
	char	**res;

	i = 0;
	while (is_number(str[i]))
		i++;
	str[i] = '\0';
	if (!(res = malloc(sizeof(char*) * 2)))
		return (NULL);
	key = str;
	i++;
	while (str[i] == ' ' || str[i] == ':')
		i++;
	value = str + i;
	res[0] = key;
	res[1] = value;
	return (res);
}

int		clean_push_key_value(char **tab, t_dico **hashtab)
{
	int		i;
	char	**res;

	i = -1;
	while (tab[++i])
	{
		if (check_line(tab[i]))
			return (-1);
		if (tab[i][0] != '\0')
		{
			res = line_by_line(tab[i]);
			add_entry(res[0], res[1], hashtab);
			free(res);
		}
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
	return (0);
}
