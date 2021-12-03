/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diplay_bsq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:03:02 by adelille          #+#    #+#             */
/*   Updated: 2021/12/03 14:37:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	print_bsq(t_data *d)
{
	write(1, &d->map[d->n], d->nbr_lines * d->len_lines - d->n);
}

void	paint_bsq(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	local_bsq_x;
	unsigned int	local_bsq_y;

	local_bsq_x = d->bsq_x - matrix[d->bsq_y][d->bsq_x];
	local_bsq_y = d->bsq_y - matrix[d->bsq_y][d->bsq_x];
	y = 0;
	while (y < d->nbr_lines)
	{
		x = 0;
		while (x < d->len_lines)
		{
			if ((y > local_bsq_x && y <= d->bsq_y)
				&& (x > local_bsq_y && x <= d->bsq_x))
				matrix[y][x] = d->filler;
			x++;
		}
		y++;
	}
}
