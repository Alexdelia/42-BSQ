/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:03:41 by adelille          #+#    #+#             */
/*   Updated: 2021/12/03 13:49:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static void	process_empty(t_data *d, unsigned short **matrix,
	unsigned int x, unsigned int y)
{
	unsigned short	tmp;

	if (x == 0 || y == 0)
		matrix[y][x] = 1;
	else
	{
		tmp = (matrix[y - 1][x] > matrix[y][x - 1]
				? matrix[y][x - 1] : matrix[y - 1][x]);
		matrix[y][x] = (tmp > matrix[y - 1][x - 1]
				? (matrix[y - 1][x - 1] + 1) : (tmp + 1));
		if (matrix[y][x] > matrix[d->bsq_y][d->bsq_x])
		{
			d->bsq_y = y;
			d->bsq_x = x;
		}
	}
}

static bool	process_end_check(t_data *d,
	unsigned int *x, unsigned int *y, unsigned int i)
{
	if (d->map[i] == '\n')
	{
		if (*x != d->len_lines)
			return (ft_pser(
					"Error: map error\t(all lines should be the same length)\n"));
		*x = -1;
		*y++;
	}
	else
		return (ft_pser(
				"Error: map error\t(all lines should be the same length)\n"));
	return (true);
}

bool	process(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = d->n;
	x = 0;
	y = 0;
	while (d->map[i])
	{
		if (y >= d->nbr_lines)
			return (ft_pser(
					"Error: map error\t(lines over number of lines in arg)\n"));
		else if (d->map[i] == d->empty)
			process_empty(d, matrix, x, y);
		else if (d->map[i] == d->obstacle)
			matrix[y][x] = 0;
		else if (!process_end_check(d, &x, &y, i))
			return (false);
		i++;
		x++;
	}
	return (true);
}
