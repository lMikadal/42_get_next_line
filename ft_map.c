/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:21:10 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/09 16:21:12 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_count_line_fd(int *count, char **av)
{
	int		fd;
	char	*text;

	fd = open(av[1], O_RDWR);
	while (1)
	{
		text = get_next_line(fd);
		if (text == NULL)
			break ;
		*count += 1;
		free(text);
	}
	close(fd);
}

static void	ft_malloc_fd(t_list *lst, t_map *map, int *fd, char **av)
{
	map->stk = (char **)malloc(sizeof(char *) * (map->line + 1));
	if (map->stk == NULL)
		exit (0);
	lst->map = (char ***)malloc(sizeof(char **) * (map->line + 1));
	if (lst->map == NULL)
		exit (0);
	*fd = open(av[1], O_RDWR);
	if (*fd == -1)
	{
		write(2, "file not correct\n", 17);
		free(map->stk);
		free(lst->map);
		exit (0);
	}
}

static void	ft_chk_line(t_list *lst, t_map *map, int i, int *chk)
{
	int			j;
	static int	line;

	j = 0;
	if (i == 0)
	{
		line = 0;
		while (lst->map[0][j] && lst->map[0][j][0] != '\n')
			j++;
		line = j;
		return ;
	}
	while (lst->map[i][j] && lst->map[i][j][0] != '\n')
		j++;
	if (line != j)
		*chk += 1;
}

static void	ft_err(int chk, t_list *lst)
{
	if (chk > 0)
	{
		write(2, "line wrong\n", 11);
		ft_free_3_d_char(lst->map);
		exit (0);
	}
}

void	ft_map(t_list *lst, char **av)
{
	t_map	map;
	int		i;
	int		fd;
	int		chk;

	ft_init_map(&map);
	ft_count_line_fd(&map.line, av);
	ft_malloc_fd(lst, &map, &fd, av);
	i = -1;
	chk = 0;
	while (1)
	{
		map.stk[++i] = get_next_line(fd);
		if (map.stk[i] == NULL)
			break ;
		lst->map[i] = ft_split(map.stk[i], ' ');
		ft_chk_line(lst, &map, i, &chk);
	}
	lst->map[i] = NULL;
	ft_free_2_d_char(map.stk);
	ft_err(chk, lst);
}
