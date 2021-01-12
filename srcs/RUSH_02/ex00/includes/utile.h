/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:56:37 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/23 22:22:45 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILE_H
# define UTILE_H
# include "dictionary.h"

unsigned	ft_strlen(char *str);
void		ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
int			ft_putstr(char *str);
int			pre_display(char *str, t_dico **hashtab);
void		head_fill(char *head, char *str, int size);
int			display_big(int len, t_dico **hashtab);
int			display_bigbig(int len, t_dico **hashtab);
int			there_is_more(char *str);
int			display_unite(char *str, int len, t_dico **hashtab);
#endif
