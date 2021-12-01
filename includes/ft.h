/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:09:14 by adelille          #+#    #+#             */
/*   Updated: 2020/10/01 12:26:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 4096

typedef struct	s_data
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
}				t_data;

void			ft_sac(char *file, unsigned short **map, t_data *data);
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
		char *buff, int a);

#endif
