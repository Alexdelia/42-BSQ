/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:23:31 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 23:39:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	init_data(t_data *data)
{
	data->nbr_lines = 0;
	data->len_lines = 0;
	data->map = NULL;
}

unsigned short	**init_matrix_file(t_data *d, unsigned short **matrix)
{
	int	i;

	matrix = malloc(sizeof(unsigned short *) * d->nbr_lines);
	if (!matrix)
	{
		ft_pser("Error: Malloc failed\n");
		return (NULL);
	}
	i = -1;
	while (++i < d->nbr_lines)
	{
		matrix[i] = malloc(sizeof(unsigned short) * d->len_lines);
		if (!matrix[i])
			return (free_matrix_i(matrix, i));
	}
	return (matrix);
}
