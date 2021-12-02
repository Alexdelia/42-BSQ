/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:23:31 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 22:43:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned short	**init_map_file(t_data *d, unsigned short **map)
{
	int	i;

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
