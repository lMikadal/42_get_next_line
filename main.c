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

	if (ac == 2)
	{
		ft_chk_fdf(av);
		ft_init_list(&lst);
		ft_map(&lst, av);
		ft_chk_map(&lst);
		lst.img = (t_img *)malloc(sizeof(t_img) + 1);
		if (!lst.img)
			return (0);
		ft_write_map(&lst, av[1]);
		ft_free_end(&lst);
	}
	else
		write(2, "argument not correct\n", 21);
	return (0);
}
