/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:20:21 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/23 23:39:54 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "utile.h"
#include <unistd.h>

int				there_is_more(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (1);
	return (0);
}

static int		display_centieme(char *str, int len, t_dico **hashtab)
{
	t_dico	*tmp;
	char	head[2];

	head_fill(head, str, 1);
	if (!(tmp = find_value(head, hashtab)))
		return (-1);
	ft_putstr(tmp->value);
	write(1, " ", 1);
	if (!(tmp = find_value("100", hashtab)))
		return (-1);
	ft_putstr(tmp->value);
	if (*(str + 1) == '0' && *(str + 2) == '0' && len > 3)
	{
		write(1, " ", 1);
		display_big((len - 3) / 3, hashtab);
	}
	return (there_is_more(str + 1));
}

static int		display_dixiem(char *str, int len, t_dico **hashtab)
{
	t_dico						*tmp;
	char						head[3];

	head_fill(head, str, 2);
	if (*str == '1' || head[1] == '0')
	{
		if (!(tmp = find_value(head, hashtab)))
			return (-1);
		ft_putstr(tmp->value);
		if (len > 3)
		{
			write(1, " ", 1);
			display_big((len - 2) / 3, hashtab);
		}
		else
			return (0);
		return (there_is_more((str + 2)));
	}
	head[1] = '0';
	if (!(tmp = find_value(head, hashtab)))
		return (-1);
	ft_putstr(tmp->value);
	return (there_is_more((str + 1)));
}

int				display_unite(char *str, int len, t_dico **hashtab)
{
	t_dico	*tmp;
	char	head[2];

	head_fill(head, str, 1);
	if (!(tmp = find_value(head, hashtab)))
		return (-1);
	ft_putstr(tmp->value);
	if (len > 3)
	{
		write(1, " ", 1);
		display_big(len / 3, hashtab);
	}
	return (there_is_more((str + 1)));
}

int				display(char *str, t_dico **hashtab, int len, int ok)
{
	while (len > 0 && ok > 0)
	{
		if (*str != '0')
		{
			if (!(len % 3))
				ok = display_centieme(str, len, hashtab);
			else if (len % 3 == 2)
			{
				ok = display_dixiem(str, len, hashtab);
				if (*(str) == '1')
					len--;
				(*(str) == '1') ? str++ : str;
			}
			else if (len % 3 == 1)
				ok = display_unite(str, len, hashtab);
			if (ok == -1)
				return (0);
			if (ok == 1)
				write(1, " ", 1);
		}
		len--;
		str++;
	}
	write(1, "\n", 1);
	return (1);
}
