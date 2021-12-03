/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diplay_bsq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:03:02 by adelille          #+#    #+#             */
/*   Updated: 2021/12/03 14:34:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_bsq(t_data *data)
{
	write(1, &d->map[d->n], d->nbr_lines * d->len_lines - d->n);
}

void	paint_bsq(t_data *d, unsigned short **matrix)
{
	int	x;
	int	y;
	int	local_bsq_x;
	int	local_bsq_y;

	local_bsq_x = data->bsq_x - map[d->bsq_y][d->bsq_x];
	local_bsq_y = data->bsq_y - map[d->bsq_y][d->bsq_x];
	y = 0;
	while (y < data->nbr_lines)
	{
		x = 0;
		while (x < data->len_lines)
		{
			if ((y > local_bsq_x && y <= d->bsq_y)
				&& (x > local_bsq_y && x <= d->bsq_x))
				map[y][x] = d->filler;
			x++;
		}
		y++;
	}
}
