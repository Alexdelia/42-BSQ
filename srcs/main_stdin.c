/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:39:11 by adelille          #+#    #+#             */
/*   Updated: 2021/12/01 15:54:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_next2(t_data *data, unsigned short **map)
{
	ft_sac2(map, data);
	ft_check_error(data);
}

int	main_ac1(void)
{
	unsigned short	**map;
	t_data			data;

	map = NULL;
	ft_initialize_data(&data);
	map = ft_read2(map, &data);
	if (data.error == 2)
		return (0);
	ft_check_error(&data);
	if (data.error == 0)
		ft_next2(&data, map);
	if (data.error == 0)
		ft_print_bsq(map, &data);
	ft_free(map, &data);
	return (0);
}
