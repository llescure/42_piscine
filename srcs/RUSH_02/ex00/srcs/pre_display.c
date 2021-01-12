/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 21:47:19 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/23 23:08:25 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "utile.h"
#include "main.h"

int		pre_display(char *str, t_dico **hashtab)
{
	int len;
	int ok;

	len = ft_strlen(str);
	ok = 1;
	if (*str == '0' && !there_is_more(str))
		display_unite(str, 1, hashtab);
	if (len > 39)
		return (0);
	return (display(str, hashtab, len, ok));
}

void	head_fill(char *head, char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
		head[i] = *str++;
	head[size] = '\0';
}

int		display_big(int len, t_dico **hashtab)
{
	t_dico *tmp;
	
	tmp = NULL;
	if (len < 1)
		return (0);
	if (len > 6)
		return (display_bigbig(len, hashtab));
	if (len == 1)
		tmp = find_value("1000", hashtab);
	else if (len == 2)
		tmp = find_value("1000000", hashtab);
	else if (len == 3)
		tmp = find_value("1000000000", hashtab);
	else if (len == 4)
		tmp = find_value("1000000000000", hashtab);
	else if (len == 5)
		tmp = find_value("1000000000000000", hashtab);
	else if (len == 6)
		tmp = find_value("1000000000000000000", hashtab);
	ft_putstr(tmp->value);
	return (1);
}

int		display_bigbig(int len, t_dico **hashtab)
{
	t_dico *tmp;

	tmp = NULL;
	if (len > 12)
		return (0);
	if (len == 7)
		tmp = find_value("1000000000000000000000", hashtab);
	else if (len == 8)
		tmp = find_value("1000000000000000000000000", hashtab);
	else if (len == 9)
		tmp = find_value("1000000000000000000000000000", hashtab);
	else if (len == 10)
		tmp = find_value("1000000000000000000000000000000", hashtab);
	else if (len == 11)
		tmp = find_value("1000000000000000000000000000000000", hashtab);
	else if (len == 12)
		tmp = find_value("1000000000000000000000000000000000000", hashtab);
	ft_putstr(tmp->value);
	return (1);
}
