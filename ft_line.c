/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:17:43 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/18 19:17:44 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_pixel *pixel)
{
	int	y;
	int	x;
	int	i;

	pixel->count_line = ((pixel->x - 1) * (pixel->y - 1) * 2) + (pixel->x - 1) + (pixel->y - 1);
	i = 0;
	y = -1;
	while (++y < pixel->y)
	{
		x = -1;
		while(++x < pixel->x)
		{
			if (y + 1 == pixel->y && x + 1 == pixel->x)
				break ;
			else if (y + 1 == pixel->y)
			{
				pixel->line[i][0] = (x % pixel->x) + (y * pixel->x);
				pixel->line[i][1] = (x % pixel->x) + (y * pixel->x) + 1;
				i++;
			}
			else if (x + 1 == pixel->x)
			{
				pixel->line[i][0] = (x % pixel->x) + (y * pixel->x);
				pixel->line[i][1] = (x % pixel->x) + ((y + 1) * pixel->x);
				i++;
			}
			else
			{
				pixel->line[i][0] = (x % pixel->x) + (y * pixel->x);
				pixel->line[i][1] = (x % pixel->x) + (y * pixel->x) + 1;
				i++;
				pixel->line[i][0] = (x % pixel->x) + (y * pixel->x);
				pixel->line[i][1] = (x % pixel->x) + ((y + 1) * pixel->x);
				i++;
			}
		}
	}
// ft_print_line(pixel);
// exit(0);
}
