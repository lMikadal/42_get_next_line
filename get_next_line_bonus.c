/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:22:44 by pmikada           #+#    #+#             */
/*   Updated: 2022/07/25 14:11:30 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_init_b(t_buff **b, int fd)
{
	*b = (t_buff *)malloc(sizeof(t_buff));
	if (*b == NULL)
		return ;
	(*b)->fd = fd;
	(*b)->r_read = 1;
	(*b)->temp_buff = NULL;
	(*b)->next = NULL;
}

void	ft_check_struct(t_buff **b, t_buff **temp, int fd)
{
	t_buff	*new;

	new = NULL;
	*temp = *b;
	while (*temp != NULL)
	{
		if ((*temp)->fd == fd)
			return ;
		if ((*temp)->next == NULL)
			break ;
		*temp = (*temp)->next;
	}
	ft_init_b(&new, fd);
	(*temp)->next = new;
	*temp = (*temp)->next;
}

char	*ft_cut(char *temp_buff)
{
	char	*m;
	int		diff;
	int		len_nl;
	int		i;

	len_nl = ft_strlen_nl(temp_buff);
	if (len_nl == -1)
		len_nl = ft_strlen(temp_buff);
	diff = ft_strlen(temp_buff) - len_nl;
	m = (char *)malloc((diff * sizeof(char)) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < diff)
		m[i++] = temp_buff[len_nl++];
	m[i] = '\0';
	free(temp_buff);
	if (m[0] == '\0')
	{
		free(m);
		return (NULL);
	}
	return (m);
}

void	ft_last(t_buff **temp, char **r_buff, int fd, t_buff **b)
{
	if ((*temp)->temp_buff != NULL)
	{
		*r_buff = ft_strdup((*temp)->temp_buff);
		(*temp)->temp_buff = ft_cut((*temp)->temp_buff);
	}
	free((*temp)->buff);
	if ((*temp)->fd == fd && *r_buff == NULL)
		ft_free_node(&(*b), &(*temp), fd);
}

char	*get_next_line(int fd)
{
	static t_buff	*b = NULL;
	t_buff			*temp;
	char			*r_buff;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (b == NULL)
		ft_init_b(&b, fd);
	ft_check_struct(&b, &temp, fd);
	r_buff = NULL;
	temp->buff = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (temp->buff == NULL)
		return (NULL);
	while (temp->r_read > 0)
	{
		temp->r_read = read(fd, temp->buff, BUFFER_SIZE);
		temp->buff[temp->r_read] = '\0';
		if (temp->r_read == 0)
			break ;
		temp->temp_buff = ft_strjoin(temp->temp_buff, temp->buff);
		if (ft_strlen_nl(temp->temp_buff) != -1)
			break ;
	}
	ft_last(&temp, &r_buff, fd, &b);
	return (r_buff);
}
