/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:44:28 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/13 18:44:29 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_count(t_list *lst, t_pixel *pixel)
{
	int		y;
	int		x;
	int		count;

	y = -1;
	count = 0;
	while (lst->map[++y])
	{
		x = -1;
		while (lst->map[y][++x])
			count++;
	}
	pixel->y = y;
	pixel->x = x;
	pixel->count = count;
}

static int	ft_color_util(char c)
{
	int	color[16];
	int	i;
	int start;

	i = 0;
	start = '0';
	while (start <= '9')
		color[i++] = start++;
	start = 'a';
	while (start <= 'f')
		color[i++] = start++;
	i = -1;
	while (color[++i] != c);
	return (i);
}

static int	ft_color(char *s)
{
	
	int	code;
	int	i;

	code = 0;
	i = -1;
	while (s[++i] != 'x');
	i++;
	code = ft_color_util(s[i++]) * 16 * 16 * 16 * 16 * 16;
	code += ft_color_util(s[i++]) * 16 * 16 * 16 * 16;
	code += ft_color_util(s[i++]) * 16 * 16 * 16;
	code += ft_color_util(s[i++]) * 16 * 16;
	code += ft_color_util(s[i++]) * 16;
	code += ft_color_util(s[i++]);
	return (code);
}

static void	ft_init_img(t_list *lst, t_pixel *pixel)
{
	int	start_x;
	int	start_y;
	int	start_z;
	int	y;
	int	x;
	int	s;

	ft_count(lst, pixel);
	start_y = 50;
	start_z = 0;
	pixel->distance_x = 45;
	pixel->distance_y = 45;
	y = -1;
	s = 0;
	pixel->count_color = 0;
	while (++y < pixel->y)
	{
		x = -1;
		start_x = 700;
		while (++x < pixel->x)
		{
			pixel->point[s][0] = start_x;
			pixel->point[s][1] = start_y;
			pixel->point[s][2] = start_z + ft_atoi(lst->map[y][x], lst, pixel);
			if (ft_strchr(lst->map[y][x], ',') != 0)
			{
				pixel->color[pixel->count_color][0] = s;
				pixel->color[pixel->count_color][1] = ft_color(lst->map[y][x]);
				pixel->count_color++;
			}
			s++;
			start_x += pixel->distance_x;
		}
		start_y += pixel->distance_y;
	}
}

void	ft_pixel(t_list *lst, t_pixel *pixel)
{
	ft_init_img(lst, pixel);
	pixel->img = (t_img *)malloc(sizeof(t_img));
	if (!pixel->img)
		return ;
}
