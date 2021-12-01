/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:03:02 by adelille          #+#    #+#             */
/*   Updated: 2021/12/01 16:15:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_print_bsq(unsigned short **map, t_data *data)
{
	int	i;
	int	j;
	int	b_sq_j;
	int	b_sq_i;

	b_sq_j = data->vertical - map[data->vertical][data->horizontal];
	b_sq_i = data->horizontal - map[data->vertical][data->horizontal];
	j = 0;
	while (j < data->nbr_lines)
	{
		i = 0;
		while (i < data->len_lines)
		{
			if (map[j][i] == 0)
				write(1, &data->obstacle, 1);
			else if ((j > b_sq_j && j <= data->vertical)
				&& (i > b_sq_i && i <= data->horizontal))
				write(1, &data->filler, 1);
			else
				write(1, &data->empty, 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
