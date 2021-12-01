/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:43:42 by adelille          #+#    #+#             */
/*   Updated: 2020/10/01 11:13:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free(unsigned short **map, t_data *data)
{
	int i;

	i = 0;
	while (i < data->nbr_lines)
	{
		free(map[i]);
		i++;
	}
	if (data->len_lines != 0)
		free(map);
}

void	ft_initialize_data(t_data *data)
{
	data->error = 0;
	data->vertical = 0;
	data->horizontal = 0;
	data->nbr_lines = 0;
	data->len_lines = 0;
	data->v_bool = 0;
	data->w_bool = 0;
}

void	ft_check_error(t_data *data)
{
	if (data->error == 1)
	{
		write(2, "map error\n", 10);
	}
}

void	ft_emergency_free(unsigned short **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
}
