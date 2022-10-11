/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:45:18 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/10 08:45:19 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_init_map(t_map *map)
{
	map->line = 0;
	map->stk = NULL;
}

void	ft_init_list(t_list *lst)
{
	lst->map = NULL;
}

int	ft_atoi(char *str, t_list *lst)
{
	int			i;
	int			m;
	long int	sum;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	m = 1;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sum * m > 2147483647 || sum * m < -2147483648)
		ft_free_end(lst);
	return ((int)(sum * m));
}
