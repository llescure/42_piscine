/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:15:10 by jbondri           #+#    #+#             */
/*   Updated: 2020/08/23 23:00:46 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utile.h"
#include "read.h"
#include "main.h"
#include <stdio.h>
#include "dictionary.h"

static void	fill_tab(t_dico **hashtab)
{
	int i;

	i = -1;
	while (++i < HASHSIZE)
		hashtab[i] = 0;
}

int			main(int argc, char **argv)
{
	char		*s_nb;
	t_dico		*hashtab[HASHSIZE];

	fill_tab(hashtab);
	if (!(argc == 2 || argc == 3))
	{
		error(BASIC);
		return (0);
	}
	s_nb = (argc == 2) ? argv[1] : argv[2];
	s_nb = refine(s_nb);
	if (!s_nb[0])
	{
		error(BASIC);
		return (0);
	}
	if (!(ft_read((argc == 2) ? "numbers.dict" : argv[1], hashtab)) ||
			!pre_display(s_nb, hashtab))
		error(DICT);
	return (0);
}
