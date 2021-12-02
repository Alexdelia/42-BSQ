/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:44:26 by adelille          #+#    #+#             */
/*   Updated: 2021/12/01 16:16:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_next(char *file, t_data *data, unsigned short **map)
{
	ft_sac(file, map, data);
	ft_check_error(data);
}

int	main_ac2plus(int ac, char **av)
{
	char			*file;
	unsigned short	**map;
	t_data			data;
	int				i;

	i = 1;
	while (i < ac)
	{
		ft_initialize_data(&data);
		file = av[i];
		map = ft_read(file, map, &data);
		if (data.error == 2)
			return (0);
		ft_check_error(&data);
		if (data.error == 0)
			ft_next(file, &data, map);
		if (data.error == 0)
			ft_print_bsq(map, &data);
		ft_free(map, &data);
		if (i + 1 < ac)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 1)
		i = main_ac2plus(ac, av);
	else
		i = main_ac1();
	return (i);
}
