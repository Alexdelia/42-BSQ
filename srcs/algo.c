/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:03:41 by adelille          #+#    #+#             */
/*   Updated: 2020/10/01 12:00:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_sac_error(t_data *data)
{
	data->error = 1;
	return (0);
}

void	ft_sac_p3(unsigned short **map, t_data *data)
{
	unsigned short	tmp;
	int				i;
	int				j;

	i = data->i;
	j = data->j;
	if (i == 0 || j == 0)
		map[j][i] = 1;
	else
	{
		tmp = (map[j - 1][i] > map[j][i - 1] ? map[j][i - 1] : map[j - 1][i]);
		map[j][i] = (tmp > map[j - 1][i - 1] ?
				(map[j - 1][i - 1] + 1) : (tmp + 1));
		if (map[j][i] > map[data->vertical][data->horizontal])
		{
			data->vertical = j;
			data->horizontal = i;
		}
	}
}

int		ft_sac_p2(unsigned short **map, t_data *data, char *buff, int a)
{
	while (buff[a])
	{
		if (data->j >= data->nbr_lines)
			return (ft_sac_error(data));
		else if (buff[a] == data->obstacle)
			map[data->j][data->i] = 0;
		else if (buff[a] == data->empty)
			ft_sac_p3(map, data);
		else if (buff[a] == '\n')
		{
			if (!(data->i == data->len_lines))
				return (ft_sac_error(data));
			data->i = -1;
			data->j++;
		}
		else
			return (ft_sac_error(data));
		a++;
		data->i++;
	}
	return (1);
}

void	ft_sac(char *file, unsigned short **map, t_data *data)
{
	int			a;
	int			ret;
	char		buff[BUFF_SIZE + 1];

	data->i = 0;
	data->j = 0;
	if ((data->fd = open(file, O_RDONLY)) < 0)
	{
		data->error = 1;
		return ;
	}
	while ((ret = read(data->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		a = 0;
		while (data->v_bool == 0 && buff[a])
		{
			if (buff[a] == '\n')
				data->v_bool += 1;
			a++;
		}
		if ((ft_sac_p2(map, data, buff, a)) == 0)
			break ;
	}
	close(data->fd);
}
