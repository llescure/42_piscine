/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:12:33 by abaudot           #+#    #+#             */
/*   Updated: 2020/08/23 22:49:00 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H
# include <stdlib.h>
# define HASHSIZE 142

typedef struct		s_dico
{
	struct s_dico	*next;
	char			*key;
	char			*value;
}					t_dico;

t_dico				*find_value(char *key, t_dico **hashtab);
t_dico				*add_entry(char *key, char *value, t_dico **hashtab);
void				free_all(t_dico **hashtab);

#endif
