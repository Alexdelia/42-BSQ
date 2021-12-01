/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:23:31 by adelille          #+#    #+#             */
/*   Updated: 2020/10/01 12:25:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			ft_store_security_struct(char *buff, t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (buff[i] != '\n')
		i++;
	data->filler = buff[--i];
	data->obstacle = buff[--i];
	data->empty = buff[--i];
	if (data->empty == data->filler || data->empty == data->obstacle ||
			data->filler == data->obstacle)
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

int				ft_len_first_line(int fd, t_data *data, int len_lines)
{
	int		i;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && data->w_bool < 2)
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
	data->error = 2;
	return (0);
}

unsigned short	**ft_read(char *file, unsigned short **map, t_data *data)
{
	int				fd;
	int				i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		data->error = 1;
		return (0);
	}
	data->len_lines = ft_len_first_line(fd, data, 0);
	close(fd);
	if (!(map = malloc(sizeof(unsigned short*) * data->nbr_lines)))
	{
		data->error = 2;
		return (0);
	}
	while (i < data->nbr_lines)
	{
		if (!(map[i] = malloc(sizeof(unsigned short) * data->len_lines)))
			return (ft_read_emergency(map, data, i));
		i++;
	}
	return (map);
}
