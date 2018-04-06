/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/06 16:22:30 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		create_line(char **rest, char **line)
{
	char		*tmp;
	int			i;
	int			j;

	tmp = NULL;
	i = 0;
	j = 0;
	while (*rest && (*rest)[i] == '\n')
		i++;
	j = i;
	while ((*rest)[j] && (*rest)[j] != '\n')
		j++;
	if (*rest)
	{
		*line = ft_strndup(*rest + i, j);
		while (*rest && (*rest)[j] == '\n')
			j++;
		tmp = ft_strdup(*rest + (i + j));
		ft_strdel(rest);
		*rest = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

static void		add_buffer_to_rest(char **rest, char buffer[])
{
	char	*tmp;

	tmp = NULL;
	if (!*rest)
		*rest = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*rest,buffer);
		ft_strdel(rest);
		*rest = ft_strdup(tmp);
		ft_strdel(&tmp);
		
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest;
	char			buffer[BUFF_SIZE + 1];
	int				i;

	*line = NULL;
	buffer[BUFF_SIZE] = '\0';
	if (fd < 0 || !line)
		return (-1);
	while ((i = read(fd, buffer, BUFF_SIZE)))
	{
		add_buffer_to_rest(&rest, buffer);
		if ((ft_strchr(rest, '\n')) || i < BUFF_SIZE)
		{
			create_line(&rest, line);
			return (1);
		}
	}
	if (i < 0)
		return (-1);
	if (rest && !*line)
	{
		create_line(&rest, line);
		return (**line ? 1 : 0);
	}
	return (*line && *rest ? 1 : 0);
}