/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:59:49 by llescure          #+#    #+#             */
/*   Updated: 2020/08/17 20:58:17 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int rslt;

	rslt = nb;
	if ((power == 0 && nb == 0) || power == 0)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	if ((power == 0 && nb == 0) || power == 0)
		return (1);
	if (nb < 0)
		rslt = rslt * -1;
	rslt = rslt * ft_recursive_power(rslt, power - 1);
	if (nb < 0 && power % 2 != 0)
		rslt = rslt * -1;
	return (rslt);
}
