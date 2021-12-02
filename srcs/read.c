/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 22:40:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static bool	map_char(t_data *d, char *buffer)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_pser("Error: map error\t(file need more than one line)\n"));
	d->filler = buffer[--i];
	d->obstacle = buffer[--i];
	d->empty = buffer[--i];
	if (d->empty == d->filler || d->empty == d->obstacle
		|| d->filler == d->obstacle)
		return (ft_pser("Error: map error\t(map char can't be the same)\n"));
	x = 0;
	d->nbr_lines = 0;
	while (x < i)
	{
		if (buffer[x] > '9' || buffer[x] < '0')
			return (ft_pser("Error: map error\t(nbr_lines isn't a number)\n"));
		d->nbr_lines *= 10 + buffer[x++] - '0';
	}
	return (true);
}

bool	read_first_line(t_data *d, char *file)
{
	char	buffer[50];

	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
		return (ft_pser("Error: Open failed\n"));
	if (read(d->fd, buffer, 50) <= 0)
		return (ft_pser("Error: map error\t(file empty)\n"));
	close(d->fd);
	if (!map_char(d, buffer))
		return (false);
	return (true);
}

bool	read_stdin(t_data *d)
{
	char	buffer[BUFFER_STDIN];
	bool	free;

	free = false;
	while (read(0, buffer, BUFFER_STDIN) != EOF)
	{
		d->stdin = ft_strjoin_free(d->stdin, buffer, free, false);
		if (!d->stdin)
			return (ft_pser("Error: Malloc failed\n"));
		if (free == false)
			free = true;
	}
	return (true);
}
