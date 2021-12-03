/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:09:14 by adelille          #+#    #+#             */
/*   Updated: 2021/12/03 12:49:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

//# include <sys/types.h>
//# include <sys/uio.h>

# define BUFFER_SIZE	4096
# define BUFFER_STDIN	280000

/*typedef struct s_data
{
	int		nbr_lines;
	int		len_lines;
	char	empty;
	char	obstacle;
	char	filler;
	short	error;
	int		vertical;
	int		horizontal;
	int		v_bool;
	int		fd;
	int		w_bool;
	int		i;
	int		j;
	char	buff[280001];
}				t_data;*/

typedef struct s_data
{
	int				fd;
	int				n;
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nbr_lines;
	unsigned int	len_lines;
}					t_data;

bool			read_file(t_data *d, char *file);
bool			read_stdin(t_data *d);

bool			process(t_data *d, unsigned short **matrix);


void			init_data(t_data *data);
unsigned short	**init_matrix(t_data *d);
void			free_matrix(unsigned short **matrix, t_data *data);
unsigned short	**free_matrix_i(unsigned short **matrix, int i);

int				ft_strlen(const char *str);
char			*ft_strjoin_free(char *s1, char *s2,
					bool const f1, bool const f2);
int				ft_ps(char *str);
bool			ft_pser(char *str);

/*void			ft_sac(char *file, unsigned short **map, t_data *data);
void			ft_print_bsq(unsigned short **map, t_data *data);
void			ft_free(unsigned short **map, t_data *data);
void			ft_initialize_data(t_data *data);
void			ft_check_error(t_data *data);
void			ft_emergency_free(unsigned short **map, int i);
void			ft_store_security_struct(char *buff, t_data *data);
int				ft_len_first_line(int fd, t_data *data, int len_lines);
unsigned short	**ft_read(char *file, unsigned short **map, t_data *data);
unsigned short	**ft_read_emergency(unsigned short **map, t_data *data, int i);
int				ft_len_first_line2(t_data *data);
unsigned short	**ft_read2(unsigned short **map, t_data *data);
void			ft_next2(t_data *data, unsigned short **map);
int				main_ac1(void);
void			ft_sac2(unsigned short **map, t_data *data);
int				ft_sac_error(t_data *data);
void			ft_sac_p3(unsigned short **map, t_data *data);
int				ft_sac_p2(unsigned short **map, t_data *data,
					char *buff, int a);*/

#endif
