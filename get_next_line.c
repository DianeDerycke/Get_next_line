/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/10 14:44:15 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		create_line(char **rest, char **line)
{
	char	*tmp;
	int		j;

	tmp = NULL;
	j = 0;
	while ((*rest)[j] && (*rest)[j] != '\n')
		j++;
	*line = ft_strndup(*rest, j);
	if ((*rest)[j] && (*rest)[j] == '\n')
		j++;
	if ((*rest)[j])
	{
		tmp = ft_strdup(*rest + j);
		ft_strdel(rest);
		*rest = ft_strdup(tmp);
		ft_strdel(&tmp);		
	}
	else
	{
		free(*rest);
		*rest = ft_strdup("");
	}
}

static void		add_buffer_to_rest(char **rest, char buffer[], int ret)
{
	char	*tmp;

	tmp = NULL;
	buffer[ret] = '\0';
	if (!(*rest))
		*rest = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*rest, buffer);
		ft_strdel(rest);
		*rest = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

int		get_next_line(const int fd, char **line)
{
	char				buffer[BUFF_SIZE + 1];
	static t_pos		pos;
	int					ret;

	ret = 0;
	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	if (!(pos.fd))
		pos.fd = fd;
	if (pos.fd != fd)
	{
		ft_strdel(&(pos.rest));
		pos.fd = fd;
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		add_buffer_to_rest(&(pos.rest), buffer, ret);
		if (pos.rest && ft_strchr(pos.rest,'\n'))
			break;
	}
	if (ret < BUFF_SIZE && !(ft_strlen(pos.rest)))
		return (0);
	 create_line(&(pos.rest), line);
	return (1);
}
