/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static bool	map_arg(t_data *d)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (d->map[i] && d->map[i] != '\n')
		i++;
	if (!d->map[i] || !d->map[i + 1])
		return (ft_pser("Error: map error\t(file need more than one line)\n"));
	d->n = i + 1;
	d->filler = d->map[--i];
	d->obstacle = d->map[--i];
	d->empty = d->map[--i];
	if (d->empty == d->filler || d->empty == d->obstacle
		|| d->filler == d->obstacle)
		return (ft_pser("Error: map error\t(map char can't be the same)\n"));
	x = 0;
	d->nbr_lines = 0;
	while (x < i)
	{
		if (d->map[x] > '9' || d->map[x] < '0')
			return (ft_pser("Error: map error\t(nbr_lines isn't a number)\n"));
		d->nbr_lines *= 10 + d->map[x++] - '0';
	}
	return (true);
}

static bool	read_len_lines(t_data *d)
{
	unsigned int	i;

	if (d->nbr_lines == 0)
		return (ft_pser("Error: map error\t(nbr_lines can't be equal to 0)\n"));
	i = d->n;
	while (d->map[i] && d->map[i] != '\n')
		i++;
	d->len_lines = i - d->n;
	if (d->len_lines == 0)
		return (ft_pser("Error: map error\t(len_lines can't be equal to 0)\n"));
	return (true);
}

bool	read_stdin(t_data *d)
{
	char	buffer[BUFFER_STDIN];
	bool	free;

	free = false;
	while (read(0, buffer, BUFFER_STDIN) != EOF)
	{
		d->map = ft_strjoin_free(d->map, buffer, free, false);
		if (!d->map)
			return (ft_pser("Error: Malloc failed\n"));
		if (free == false)
			free = true;
	}
	if (!map_arg(d) || !read_len_lines(d))
		return (false);
	return (true);
}

bool	read_file(t_data *d, char *file)
{
	char	buffer[BUFFER_SIZE];
	bool	free;

	d->map = NULL;
	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
		return (ft_pser("Error: Open failed\n"));
	free = false;
	while (read(d->fd, buffer, BUFFER_SIZE) != EOF)
	{
		d->map = ft_strjoin_free(d->map, buffer, free, false);
		if (!d->map)
			return (ft_pser("Error: Malloc failed\n"));
		if (free == false)
			free = true;
	}
	close(d->fd);
	if (!map_arg(d) || !read_len_lines(d))
		return (false);
	return (true);
}
