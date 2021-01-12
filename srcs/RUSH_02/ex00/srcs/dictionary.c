/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:21:18 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/23 22:31:04 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "utile.h"

static unsigned		hash(char *str)
{
	unsigned hashval;

	hashval = 0;
	while (*str)
		hashval = *str++ + (31 * hashval);
	return (hashval % HASHSIZE);
}

static char			*ft_strdup(char *str)
{
	char *ans;

	if (!(ans = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	ft_strcpy(ans, str);
	return (ans);
}

t_dico				*find_value(char *key, t_dico **hashtab)
{
	t_dico	*entry;

	entry = hashtab[hash(key)];
	while (entry)
	{
		if (!ft_strcmp(key, entry->key))
			return (entry);
		entry = entry->next;
	}
	return (0);
}

t_dico				*add_entry(char *key, char *value, t_dico **hashtab)
{
	t_dico		*entry;
	unsigned	hashval;

	if (!(entry = find_value(key, hashtab)))
	{
		if (!(entry = (t_dico *)malloc(sizeof(t_dico))))
			return (0);
		if (!(entry->key = ft_strdup(key)))
			return (0);
		hashval = hash(key);
		entry->next = hashtab[hashval];
		hashtab[hashval] = entry;
	}
	else
		free((void *)entry->value);
	if (!(entry->value = ft_strdup(value)))
		return (0);
	return (entry);
}

void				free_all(t_dico **hashtab)
{
	t_dico	*tmp;
	t_dico	*to_remov;
	int		i;

	i = 0;
	while (i < HASHSIZE)
		if ((tmp = hashtab[i++]))
		{
			while (tmp->next)
			{
				to_remov = tmp->next;
				tmp->next = to_remov->next;
				free((void *)to_remov->key);
				free((void *)to_remov->value);
				free(to_remov);
			}
			free((void *)tmp->key);
			free((void *)tmp->value);
			free(tmp);
		}
}
