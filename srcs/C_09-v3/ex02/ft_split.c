/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:24:16 by llescure          #+#    #+#             */
/*   Updated: 2020/08/26 17:46:58 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		sep(char c, char *charset);
int		ft_count_words(char *str, char *charset);
int		ft_c(char *str, char *charset, int pos);
char	**ft_display(char *str, char *charset, char **tab);

char	**ft_split(char *str, char *charset)
{
	char				**tab;

	if (!(tab = malloc(sizeof(char *) * ft_count_words(str, charset) + 1)))
		return (NULL);
	tab = ft_display(str, charset, tab);
	tab[ft_count_words(str, charset)] = 0;
	return (tab);
}

int		sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		i++;
		if (sep(str[i], charset) == 0 &&
				(sep(str[i + 1], charset) == 1 || str[i + 1] == '\0'))
		{
			if (str[i] == '\0')
				return (count);
			count++;
		}
	}
	return (count);
}

int		ft_c(char *str, char *charset, int pos)
{
	int i;

	i = pos;
	if (i != 0)
		i++;
	while (str[i] != '\0')
	{
		if (sep(str[i], charset) == 1 || str[i] == '\0')
		{
			break ;
		}
		i++;
	}
	return (i - pos);
}

char	**ft_display(char *str, char *charset, char **tab)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	while (++i < ft_count_words(str, charset))
	{
		while (str[++j] != '\0')
		{
			if (((sep(str[j], charset) == 0 && sep(str[j - 1], charset) == 1))
				|| (j == 0 && sep(str[j], charset) == 0))
			{
				tab[i] = malloc(sizeof(char) * ft_c(str, charset, j) + 1);
				k = -1;
				while ((++k < ft_c(str, charset, j) || str[j] != '\0') &&
						(sep(str[j], charset) == 0))
					tab[i][k] = str[j++];
				tab[i][k] = '\0';
				break ;
			}
		}
	}
	return (tab);
}
