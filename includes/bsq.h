/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:09:14 by adelille          #+#    #+#             */
/*   Updated: 2021/12/05 21:43:02 by adelille         ###   ########.fr       */
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
#  define BUFFER_SIZE	10000
# endif

# define BUFFER_STDIN	280000

# ifndef DEBUG
#  define DEBUG			0
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

bool			process(t_data *d, unsigned short **matrix);

void			paint_bsq(t_data *d, unsigned short **matrix);
void			print_bsq(t_data *data);
void			print_debug(t_data *d, unsigned short **matrix);

void			init_data(t_data *data);
unsigned short	**init_matrix(t_data *d);
void			free_matrix(unsigned short **matrix, t_data *data);
unsigned short	**free_matrix_i(unsigned short **matrix, int i);

int				ft_strlen(const char *str);
char			*ft_strjoin_free(char *s1, char *s2,
					bool const f1, bool const f2);
int				ft_ps(char *str);
bool			ft_pser(char *str);

#endif
