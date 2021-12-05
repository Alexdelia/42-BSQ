/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/05 23:10:18 by adelille         ###   ########.fr       */
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
		d->nbr_lines = d->nbr_lines * 10 + d->map[x++] - '0';
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

bool	read_map(t_data *d, int fd, int buffer_size)
{
	char	*buffer;
	int		ret;
	int		size;

	d->map = (char *)malloc(sizeof(char) * BUFFER_INIT + 1);
	if (!d->map)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(fd, d->map, BUFFER_INIT);
	if (ret != 0 && ret != EOF)
	{
		d->map[ret] = '\0';
		size = ret;
		buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
		if (!buffer)
			return (ft_pser("Error: Malloc failed\n"));
		ret = read(fd, buffer, buffer_size);
	}
	while (ret != 0 && ret != EOF)
	{
		buffer[ret] = '\0';
		d->map = ft_strjoin_bsq(d->map, size, buffer, buffer_size);
		size += ret;
		if (!d->map)
			return (ft_pser("Error: Malloc failed\n"));
		ret = read(fd, buffer, buffer_size);
	}
	free(buffer);
	return (true);
}

bool	read_stdin(t_data *d)
{
	if (!read_map(d, 0, BUFFER_STDIN))
		return (false);
	if (!map_arg(d) || !read_len_lines(d))
		return (false);
	return (true);
}

bool	read_file(t_data *d, char *file)
{
	d->map = NULL;
	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
		return (ft_pser("Error: Open failed\n"));
	if (!read_map(d, d->fd, BUFFER_SIZE))
	{
		close(d->fd);
		return (false);
	}
	close(d->fd);
	if (!map_arg(d) || !read_len_lines(d))
		return (false);
	return (true);
}
