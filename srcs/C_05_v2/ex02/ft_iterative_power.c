/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:54:49 by llescure          #+#    #+#             */
/*   Updated: 2020/08/17 16:12:47 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int rslt;

	rslt = 1;
	i = 1;
	if (power < 0)
		return (0);
	if ((power == 0 && nb == 0) || power == 0)
		return (1);
	if (power == 0 & nb < 0)
		return (nb);
	if (power == 1)
		return (nb);
	else
	{
		while (i <= power)
		{
			rslt = rslt * nb;
			i++;
		}
	}
	return (rslt);
}
