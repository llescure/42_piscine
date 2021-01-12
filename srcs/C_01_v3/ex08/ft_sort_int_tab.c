/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:38:28 by llescure          #+#    #+#             */
/*   Updated: 2020/08/21 12:01:50 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	if (size == 0)
		return ;
	while (i <= size - 1)
	{
		j = i + 1;
		while (j <= size - 1)
		{
			if (tab[i] >= tab[j])
				ft_swap(&tab[j], &tab[i]);
			j++;
		}
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int help;

	help = *a;
	*a = *b;
	*b = help;
}
