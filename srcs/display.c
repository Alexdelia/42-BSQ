/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:03:02 by adelille          #+#    #+#             */
/*   Updated: 2021/12/05 23:00:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	print_bsq(t_data *d)
{
	(void)!write(1, &d->map[d->n], d->nbr_lines * (d->len_lines + 1));
}

static void	print_debug(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;

	printf("\n");
	y = 0;
	while (y < d->nbr_lines)
	{
		x = 0;
		while (x < d->len_lines)
		{
			printf("%d", matrix[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}

static void	paint_bsq(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	top_left_x;
	unsigned int	top_left_y;

	top_left_x = d->bsq_x - matrix[d->bsq_y][d->bsq_x] + 1;
	top_left_y = d->bsq_y - matrix[d->bsq_y][d->bsq_x] + 1;
	y = 0;
	while (y <= d->nbr_lines)
	{
		x = 0;
		while (x <= d->len_lines)
		{
			if ((y >= top_left_y && y <= d->bsq_y)
				&& (x >= top_left_x && x <= d->bsq_x))
				d->map[(y * (d->len_lines + 1)) + x + d->n] = d->filler;
			x++;
		}
		y++;
	}
}

void	display_bsq(t_data *d, unsigned short **matrix)
{
	paint_bsq(d, matrix);
	print_bsq(d);
	if (DEBUG != 0)
		print_debug(d, matrix);
}
