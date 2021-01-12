/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:56:16 by llescure          #+#    #+#             */
/*   Updated: 2020/08/23 21:18:49 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "read.h"
#define BUF_SIZE 4096

int		ft_find_buffer_size(char *file)
{
	long	compt;
	char	buff[1];
	int		fd;
	int		temp;

	compt = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while ((temp = read(fd, buff, 1) > 0))
		compt += temp;
	if (temp == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (compt);
}

int		ft_read(char *file, t_dico **hashtab)
{
	const int	size_of_file = ft_find_buffer_size(file);
	char		*tab;
	int			fd;
	int			ret;
	char		**dest;

	if ((tab = malloc(sizeof(char) * size_of_file + 1)) == NULL)
		return (0);
	if (((fd = open(file, O_RDONLY)) != -1) &&
			(ret = read(fd, tab, (size_of_file)) != -1) &&
			close(fd) != -1)
	{
		dest = ft_split(tab, "\n");
		if (clean_push_key_value(dest, hashtab) == -1)
			return (0);
	}
	free(tab);
	return (1);
}
