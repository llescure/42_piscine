/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:58:49 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/22 19:27:32 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	make_hashset(char *charset, int *hashset)
{
	int i;

	i = -1;
	while (++i < 126)
		hashset[i] = 0;
	while (*charset)
		hashset[*charset++ % 126] = 1;
}

static int	find_all_words(char *str, char *charset, int *hashset)
{
	int ans;
	int is_in_word;

	ans = 0;
	is_in_word = 0;
	make_hashset(charset, hashset);
	while (*str)
	{
		if (!hashset[*str++ % 126])
		{
			if (!is_in_word)
				ans++;
			is_in_word = 1;
		}
		else
			is_in_word = 0;
	}
	return (ans);
}

static char	*add_ellement(char *dest, char *str, int size)
{
	int i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i++ < size)
		*dest++ = *str++;
	*dest = 0;
	return (dest - size);
}

static int	split_str(char **ans, char *str, int *hashset)
{
	int word_size;

	word_size = 0;
	while (*str)
	{
		if (!hashset[*str % 126])
			word_size++;
		else if (word_size)
		{
			if (!(*ans = add_ellement(*ans, str - word_size, word_size)))
				return (0);
			word_size = 0;
			ans++;
		}
		str++;
	}
	if (word_size)
	{
		if (!(*ans = add_ellement(*ans, str - word_size, word_size)))
			return (0);
		ans++;
	}
	*ans = 0;
	return (1);
}

char		**ft_split(char *str, char *charset)
{
	char		**ans;
	int			hashset[126];
	const int	split_nth = find_all_words(str, charset, hashset) + 1;

	if (!(ans = (char**)(malloc(sizeof(char*) * split_nth))))
		return (NULL);
	if (!split_str(ans, str, hashset))
		return (NULL);
	return (ans);
}
