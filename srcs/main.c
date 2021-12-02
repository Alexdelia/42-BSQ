/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:44:26 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 22:49:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

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

bool	solve_from_file(t_data *d, char *file)
{
	unsigned short	**map;

	init_data(d);
	if (!read_first_line(d, file))
		return (false);
	map = init_map_file(d, map);
	if (!map)
		return (false);
	if (!process_from_file(d, map, file))
		return (false); // might free
	print_bsq(map, d); // need to change write(1, &char, 1);
	// free/clear or in main
	return (true);
}

bool	solve_from_stdin(t_data *d)
{
	init_data(d);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	d;
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac && solve_from_file(&d, av[i]))
			i++;
		if (i < ac)
			return (1);
	}
	else
		return (solve_from_stdin(&d));
	// free/clear
	return (0);
}
