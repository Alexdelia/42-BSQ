/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:09:14 by adelille          #+#    #+#             */
/*   Updated: 2021/12/09 16:27:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100000000
# endif

# define BUFFER_INIT	4096
# define BUFFER_STDIN	280000

# ifndef DEBUG
#  define DEBUG			0
# endif

# ifndef PRINT
#  define PRINT			0
# endif

typedef struct s_data
{
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nbr_lines;
	unsigned int	len_lines;
	unsigned int	bsq_x;
	unsigned int	bsq_y;
	unsigned long	n;
	int				fd;
}					t_data;

bool			read_file(t_data *d, char *file);
bool			read_stdin(t_data *d);
bool			map_arg(t_data *d);
bool			read_len_lines(t_data *d);

bool			process(t_data *d, unsigned short **matrix);

void			display_bsq(t_data *d, unsigned short **matrix);

void			init_data(t_data *data);
unsigned short	**init_matrix(t_data *d);
void			free_matrix(unsigned short **matrix, t_data *data);
unsigned short	**free_matrix_i(unsigned short **matrix, int i);

char			*ft_strjoin_bsq(char *s1, const size_t size1,
					char *s2, const size_t size2);
bool			ft_pser(char *str);

#endif
