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

int		ft_strlen(char *s);
void	ft_init_map(t_map *map);
void	ft_init_list(t_list *lst);
char	**ft_split(char *s, char c);
void	ft_free_2_d_char(char **s);
void	ft_free_3_d_char(char ***s);
void	ft_map(t_list *lst, char **av);

#endif
