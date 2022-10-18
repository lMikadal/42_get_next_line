/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:08:35 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/08 16:08:38 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_chk_fdf(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (len >= 4 && (av[1][len - 1] != 'f' || av[1][len - 2] != 'd' \
		|| av[1][len - 3] != 'f' || av[1][len - 4] != '.'))
	{
		write(2, "file name wrong\n", 16);
		exit (0);
	}
}

static void	ft_chk_str(char *s, int *err)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] == ',')
			break ;
		else if (s[i] == '-' && (s[i + 1] < '0' || s[i + 1] > '9'))
		{
			*err += 1;
			break ;
		}
		else if ((s[i] < '0' || s[i] > '9') && s[i] != '\n' && s[i] != '-')
		{
			*err += 1;
			break ;
		}
		i++;
	}
}

static void	ft_chk_map(t_list *lst)
{
	int	l;
	int	s;
	int	err;

	l = -1;
	err = 0;
	while (lst->map[++l])
	{
		s = -1;
		while (lst->map[l][++s])
			ft_chk_str(lst->map[l][s], &err);
	}
	if (err > 0)
	{
		write(2, "data wrong\n", 11);
		ft_free_3_d_char(lst->map);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_list	lst;
	t_pixel	*pixel;

	if (ac == 2)
	{
		ft_chk_fdf(av);
		ft_init_list(&lst);
		ft_map(&lst, av);
		ft_chk_map(&lst);
		pixel = (t_pixel *)malloc(sizeof(t_pixel));
		if (!pixel)
			return (0);
		ft_pixel(&lst, pixel);
		ft_line(pixel);
ft_print_color(pixel);
		ft_write_map(pixel, av[1]);

		ft_free_end(&lst, pixel);
	}
	else
		write(2, "argument not correct\n", 21);
	return (0);
}

void	ft_print_pixel(t_pixel *pixel)
{
	int	i = -1;
	while (++i < pixel->count)
		printf("point[%d](x = %f, y = %f, z = %f)\n", i, pixel->point[i][0], pixel->point[i][1], pixel->point[i][2]);
}

void	ft_print_map(t_list *lst)
{
	int	i = -1;
	int	j;
	while (lst->map[++i])
	{
		j = -1;
		while (lst->map[i][++j])
			printf("map[%d][%d] = |%s|\n", i, j, lst->map[i][j]);
	}
}

void	ft_print_color(t_pixel *pixel)
{
	int	i = -1;
	while (++i < pixel->count_color)
		printf("color: index[%d] = %d\n", pixel->color[i][0], pixel->color[i][1]);
}

void	ft_print_line(t_pixel *pixel)
{
	int	i = -1;
	while (++i < pixel->count_line)
		printf("line %d: x %d,y %d\n", i, pixel->line[i][0], pixel->line[i][1]);
}