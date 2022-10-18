/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:08:48 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/08 16:08:50 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	int		line;
	char	**stk;
}	t_map;

typedef struct s_list
{
	char	***map;
}	t_list;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_img;

typedef struct s_pixel
{
	double	point[1000000][3];
	int		line[1000000][2];
	int		color[1000000][2];
	int		y;
	int		x;
	int		count;
	int		count_line;
	int		count_color;
	int		distance_x;
	int		distance_y;
	t_img	*img;
}	t_pixel;

int		ft_strlen(char *s);
void	ft_init_map(t_map *map);
void	ft_init_list(t_list *lst);
char	*ft_strchr(char *s, int c);
int		ft_atoi(char *str, t_list *lst, t_pixel *pixel);
char	**ft_split(char *s, char c);
void	ft_free_2_d_char(char **s);
void	ft_free_3_d_char(char ***s);
void	ft_free_end(t_list *lst, t_pixel *pixel);
void	ft_map(t_list *lst, char **av);
void	ft_pixel(t_list *lst, t_pixel *pixel);
void	ft_line(t_pixel *pixel);
void	ft_write_map(t_pixel *pixel, char *av);

void	ft_print_pixel(t_pixel *pixel);
void	ft_print_map(t_list *lst);
void	ft_print_color(t_pixel *pixel);
void	ft_print_line(t_pixel *pixel);
#endif
