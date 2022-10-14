/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:11:19 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/10 10:11:21 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_2_d_char(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	ft_free_3_d_char(char ***s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_free_2_d_char(s[i++]);
	free(s);
}

void	ft_free_end(t_list *lst, t_pixel *pixel)
{
	ft_free_3_d_char(lst->map);
	free(pixel->img);
	free(pixel);
}
