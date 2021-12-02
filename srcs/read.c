/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 19:05:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static bool	map_char(t_data *d, char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_pser("Error: map error\t(file need more than one line)\n")
			* 0);
	d->filler = buffer[--i];
	d->obstacle = buffer[--i];
	d->empty = buffer[--i];
	if (d->empty == d->filler || d->empty == d->obstacle
		|| d->filler == d->obstacle)
		return (ft_pser("Error: map error\t(map char can't be the same)\n")
			* 0);
	return (true);
}

bool	read_first_line(t_data *d)
{
	char	buffer[50];

	if (read(d->fd, buffer, 50) <= 0)
		return (ft_pser("Error: map error\t(file empty)\n") * 0);
	if (!map_char(d, buffer))
		return (false);
	// nbr_lines
	return (true);
}
