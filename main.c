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

int	main(int ac, char **av)
{
	t_list	lst;

	if (ac == 2)
	{
		ft_chk_fdf(av);
		ft_init_list(&lst);
		ft_map(&lst, av);
// int	j;
// int	i=0;
// while (lst.map[i])
// {
// 	j = 0;
// 	while (lst.map[i][j])
// 	{
// 		printf("map[%d][%d] = |%s|\n", i, j, lst.map[i][j]);
// 		j++;
// 	}
// 	i++;
// }
		ft_free_3_d_char(lst.map);
	}
	else
		write(2, "argument not correct\n", 21);
	return (0);
}
