/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:34:38 by llescure          #+#    #+#             */
/*   Updated: 2020/08/23 21:07:17 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include "dictionary.h"

int		is_number(char c);
int		is_printable(char c);
int		check_line(char *str);
char	**line_by_line(char *str);
int		clean_push_key_value(char **tab, t_dico **hashtab);
int		ft_read(char *file, t_dico **hashtab);
int		ft_find_buffer_size(char *file);
char	**ft_split(char *str, char *charset);
#endif
