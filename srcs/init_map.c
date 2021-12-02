/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:23:31 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 18:40:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned short	**init_map_file(char *file, unsigned short **map, t_data *d)
{
	int	i;

	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
	{
		ft_pser("Error: Open failed\n");
		return (NULL);
	}
	if (!read_first_line(d))
		return (NULL);
	//close(fd);
	map = malloc(sizeof(unsigned short *) * d->nbr_lines);
	if (!map)
	{
		ft_pser("Error: Malloc failed\n");
		return (NULL);
	}
	i = -1;
	while (++i < d->nbr_lines)
	{
		map[i] = malloc(sizeof(unsigned short) * d->len_lines);
		if (!map[i])
			return (free_map_i(map, i));
	}
	return (map);
}
