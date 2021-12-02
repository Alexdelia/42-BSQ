/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:03:41 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 23:14:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_sac_p3(unsigned short **map, t_data *d)
{
	unsigned short	tmp;
	int				i;
	int				j;

	i = d->i;
	j = d->j;
	if (i == 0 || j == 0)
		map[j][i] = 1;
	else
	{
		tmp = (map[j - 1][i] > map[j][i - 1] ? map[j][i - 1] : map[j - 1][i]);
		map[j][i] = (tmp > map[j - 1][i - 1]
				? (map[j - 1][i - 1] + 1) : (tmp + 1));
		if (map[j][i] > map[d->vertical][d->horizontal])
		{
			d->vertical = j;
			d->horizontal = i;
		}
	}
}

int	ft_sac_p2(t_data *d, unsigned short **map, char *buffer, int n)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (buffer[n])
	{
		if (x >= d->nbr_lines)
			return (false); // might map error
		else if (buffer[n] == d->obstacle)
			map[x][y] = 0;
		else if (buffer[n] == d->empty)
			ft_sac_p3(map, d);
		else if (buffer[n] == '\n')
		{
			if (y != d->len_lines)
				return (false); // might map error
			y = -1;
			x++;
		}
		else
			return (false); // might map error
		n++;
		y++;
	}
	return (1);
}

bool	process_file(t_data *d, unsigned short **map, char *file)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;

	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
		return (ft_pser("Error: Open failed\n"));
	ret = read(d->fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (!ft_sac_p2(d, map, buffer, i))
			return (false);
		// ret = read(d->fd, buffer, BUFFER_SIZE);
	}
	close(d->fd);
}
