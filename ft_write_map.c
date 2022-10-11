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

static void	ft_mlx_pixel_put(t_list *lst, int x, int y, int color)
{
	char	*dst;

	dst = lst->img->addr + ((y * lst->img->line) + (x * \
			(lst->img->bits / lst->line)));
	*(unsigned int *)dst = color;
}

void	ft_write_map(t_list *lst, char *av)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 900, av);
	lst->img->img = mlx_new_image(mlx, 1600, 900);
	lst->img->addr = mlx_get_data_addr(lst->img->img, &lst->img->bits, \
						&lst->img->line, &lst->img->endian);
	
	mlx_put_image_to_window(mlx, mlx_win, lst->img->img, 0, 0);
	mlx_loop(mlx);
}
