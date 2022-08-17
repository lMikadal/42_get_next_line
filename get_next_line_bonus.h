/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:23:05 by pmikada           #+#    #+#             */
/*   Updated: 2022/07/25 14:08:09 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buff
{
	int				fd;
	int				r_read;
	char			*temp_buff;
	char			*buff;
	struct s_buff	*next;
}	t_buff;

int		ft_strlen(char *s);
int		ft_strlen_nl(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
void	ft_free_node(t_buff **b, t_buff **temp, int fd);
char	*get_next_line(int fd);

#endif
