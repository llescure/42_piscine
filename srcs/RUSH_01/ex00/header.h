/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:05:00 by thsembel          #+#    #+#             */
/*   Updated: 2020/08/15 19:19:40 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

int		**ft_init_grid(void);
int		**ft_init_rule(char *str);
int		ft_fill_grid(int **grid, int **rule, int pos);
int		ft_is_twice(int **grid, int y, int x, int s);
int		ft_check_left(int **grid, int **rule, int y);
int		ft_check_right(int **grid, int **rule, int y);
int		ft_check_down(int **grid, int **rule, int x);
int		ft_check_up(int **grid, int **rule, int x);
void	ft_display(int **grid);

#endif
