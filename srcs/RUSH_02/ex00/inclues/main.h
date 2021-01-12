/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:14:53 by jbondri           #+#    #+#             */
/*   Updated: 2020/08/23 22:19:54 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define BASIC 0
# define DICT 1
# include "dictionary.h"

char	*refine(char *str);
void	error(int stat);
int		display(char *str, t_dico **hashtab, int len, int ok);
#endif
