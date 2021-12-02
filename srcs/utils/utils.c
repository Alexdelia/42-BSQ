/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:43:42 by adelille          #+#    #+#             */
/*   Updated: 2021/12/02 22:30:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ps(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

bool	ft_pser(char *str)
{
	write(2, str, ft_strlen(str));
	return (false);
}

void	init_data(t_data *data)
{
	data->nbr_lines = 0;
	data->len_lines = 0;
}
