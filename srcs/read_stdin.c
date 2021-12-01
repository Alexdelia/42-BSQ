/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:33:07 by adelille          #+#    #+#             */
/*   Updated: 2020/10/01 12:18:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				ft_len_first_line2(t_data *data)
{
	int		i;
	int		len_lines;

	i = 0;
	len_lines = 0;
	while (data->buff[i] && data->w_bool < 2)
	{
		if (data->w_bool == 0)
			ft_store_security_struct(data->buff, data);
		i = 0;
		while (data->buff[i] && data->w_bool < 2)
		{
			if (data->buff[i] == '\n')
				data->w_bool++;
			if (data->w_bool == 1)
				len_lines++;
			i++;
		}
	}
	len_lines--;
	return (len_lines);
}

unsigned short	**ft_read2(unsigned short **map, t_data *data)
{
	int				i;
	int				ret;

	i = 0;
	data->len_lines = ft_len_first_line2(data);
	ret = read(0, data->buff, 280000);
	data->buff[ret] = '\0';
	if (!(map = malloc(sizeof(unsigned short*) * 1001)))
	{
		data->error = 2;
		return (0);
	}
	while (i < data->nbr_lines)
	{
		if (!(map[i] = malloc(sizeof(unsigned short) * 1001)))
			return (ft_read_emergency(map, data, i));
		i++;
	}
	return (map);
}
