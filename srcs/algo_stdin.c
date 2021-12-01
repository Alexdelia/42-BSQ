/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 12:01:01 by adelille          #+#    #+#             */
/*   Updated: 2020/10/01 12:16:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_sac2(unsigned short **map, t_data *data)
{
	int			a;

	data->i = 0;
	data->j = 0;
	a = 0;
	while (data->v_bool == 0 && data->buff[a])
	{
		if (data->buff[a] == '\n')
			data->v_bool += 1;
		a++;
	}
	if ((ft_sac_p2(map, data, data->buff, a)) == 0)
		return ;
	return ;
}
