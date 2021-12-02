/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:23:31 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 18:26:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_store_security_struct(char *buff, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i] != '\n')
		i++;
	data->filler = buff[--i];
	data->obstacle = buff[--i];
	data->empty = buff[--i];
	if (data->empty == data->filler || data->empty == data->obstacle
		|| data->filler == data->obstacle)
		data->error = 1;
	j = 0;
	data->nbr_lines = 0;
	while (j < i)
	{
		if (buff[j] > '9' || buff[j] < '0')
		{
			data->error = 1;
			return ;
		}
		data->nbr_lines = data->nbr_lines * 10 + buff[j++] - '0';
	}
}

int	ft_len_first_line(int fd, t_data *data, int len_lines)
{
	int		i;
	int		ret;
	char	buff[50];

	while ((ret = read(fd, buff, 50)) > 0 && data->w_bool < 2)
	{
		buff[ret] = '\0';
		if (data->w_bool == 0)
			ft_store_security_struct(buff, data);
		i = 0;
		while (buff[i] && data->w_bool < 2)
		{
			if (buff[i] == '\n')
				data->w_bool++;
			if (data->w_bool == 1)
				len_lines++;
			i++;
		}
	}
	len_lines--;
	if (ret < 0)
		data->error = 1;
	return (len_lines);
}

unsigned short	**ft_read_emergency(unsigned short **map, t_data *data, int i)
{
	ft_emergency_free(map, i);
	return (NULL);
}

unsigned short	**init_map_file(char *file, unsigned short **map, t_data *data)
{
	int	i;

	if ((data->fd = open(file, O_RDONLY)) < 0)
	{
		ft_pser("Error: Open failed\n");
		return (NULL);
	}
	data->len_lines = ft_len_first_line(data->fd, data, 0);
	//close(fd);
	map = malloc(sizeof(unsigned short *) * data->nbr_lines);
	if (!map)
	{
		ft_pser("Error: Malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (i < data->nbr_lines)
	{
		map[i] = malloc(sizeof(unsigned short) * data->len_lines);
		if (!map[i])
			return (ft_read_emergency(map, data, i));
		i++;
	}
	return (map);
}
