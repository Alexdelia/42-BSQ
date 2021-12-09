/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:28 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 16:20:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static bool	read_big_map(t_data *d, int fd, size_t buffer_size, size_t size)
{
	char	*buffer;
	ssize_t	ret;

	buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
	if (!buffer)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(fd, buffer, buffer_size);
	buffer[ret] = '\0';
	while (ret != 0 && ret != EOF)
	{
		d->map = ft_strjoin_bsq(d->map, size, buffer, buffer_size);
		if (!d->map)
			return (ft_pser("Error: Malloc failed\n"));
		size += ret;
		ret = read(fd, buffer, buffer_size);
		buffer[ret] = '\0';
	}
	free(buffer);
	return (true);
}

static bool	read_map(t_data *d, int fd, size_t buffer_size)
{
	ssize_t		ret;

	d->map = (char *)malloc(sizeof(char) * BUFFER_INIT + 1);
	if (!d->map)
		return (ft_pser("Error: Malloc failed\n"));
	ret = read(fd, d->map, BUFFER_INIT);
	d->map[ret] = '\0';
	if (ret != 0 && ret != EOF)
		if (!read_big_map(d, fd, buffer_size, ret))
			return (false);
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
