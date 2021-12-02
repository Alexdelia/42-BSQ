/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:43:42 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 18:33:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	free_map(unsigned short **map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_lines)
	{
		free(map[i]);
		i++;
	}
	if (data->len_lines != 0)
		free(map);
}

unsigned short	**free_map_i(unsigned short **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
	return (NULL);
}
