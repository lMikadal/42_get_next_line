/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:04:52 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/10 17:04:53 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->img->addr + ((y * pixel->img->line) + (x * \
			(pixel->img->bits / 8)));
	*(unsigned int *)dst = color;
}

static void	ft_rotate_z(t_pixel *pixel, double angle)
{
	double	sin_ang;
	double	cos_ang;
	int		i;
	double	x;
	double	y;
	double	s_y;

	sin_ang = sin(angle);
	cos_ang = cos(angle);
	i = -1;
	s_y = (pixel->point[0][1] * cos_ang + pixel->point[0][0] * sin_ang) - pixel->point[0][1];
	while (++i < pixel->count)
	{
		x = pixel->point[i][0];
		y = pixel->point[i][1];
		pixel->point[i][0] = x * cos_ang - y * sin_ang;
		pixel->point[i][1] = (y * cos_ang + x * sin_ang) - s_y;
	}
}

static void	ft_rotate_x(t_pixel *pixel, double angle)
{
	double	sin_ang;
	double	cos_ang;
	int		i;
	double	y;
	double	z;
	double	s_y;

	sin_ang = sin(angle);
	cos_ang = cos(angle);
	i = -1;
	s_y =  pixel->point[0][1] - (pixel->point[0][1] * cos_ang + pixel->point[0][2] * sin_ang);
	while (++i < pixel->count)
	{
		y = pixel->point[i][1];
		z = pixel->point[i][2];
		pixel->point[i][1] = (y * cos_ang - z * sin_ang) + s_y;
		pixel->point[i][2] = z * cos_ang + y * sin_ang;
	}
}

static void	ft_rotate_y(t_pixel *pixel, double angle)
{
	double	sin_ang;
	double	cos_ang;
	int		i;
	double	x;
	double	z;

	sin_ang = sin(angle);
	cos_ang = cos(angle);
	i = -1;
	while (++i < pixel->count)
	{
		x = pixel->point[i][0];
		z = pixel->point[i][2];
		pixel->point[i][0] = x * cos_ang + z * sin_ang;
		pixel->point[i][2] = z * cos_ang - x * sin_ang;
	}
}

static int	ft_chk_color(int i, t_pixel *pixel)
{
	int	j;

	j = 0;
	while(j < pixel->count_color)
	{
		if (i == pixel->color[j][0])
			return (pixel->color[j][1]);
		j++;
	}
	return (-1);
}	

void	ft_write_map(t_pixel *pixel, char *av)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 900, av);
	pixel->img->img = mlx_new_image(mlx, 1600, 900);
	pixel->img->addr = mlx_get_data_addr(pixel->img->img, &pixel->img->bits, \
						&pixel->img->line, &pixel->img->endian);

ft_rotate_z(pixel, 0.524);
ft_rotate_y(pixel, 0);
ft_rotate_x(pixel, 0.524);
ft_print_pixel(pixel);
int j = -1;
int	color;
int	x;
int	y;
while (++j < pixel->count)
{
 	color = 0xffffff;
	x = pixel->point[j][0];
	y = pixel->point[j][1];
	if (ft_chk_color(j, pixel) != -1)
		ft_mlx_pixel_put(pixel, x, y, ft_chk_color(j, pixel));
	else
		ft_mlx_pixel_put(pixel, x, y, color);
}

	mlx_put_image_to_window(mlx, mlx_win, pixel->img->img, 0, 0);
	mlx_loop(mlx);
}
