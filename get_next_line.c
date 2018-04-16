/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/13 15:15:49 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin_free(char *s1, char *s2)
{
	char			*str;

	str = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char*)ft_memalloc(sizeof(char) *
			((ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	ft_strdel(&s1);
	return (str);
}

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
		ft_strdel(rest);
		*rest = ft_strdup("");
	}
}

static void		add_buffer_to_rest(char **rest, char buffer[], int ret)
{
	buffer[ret] = '\0';
	if (!(*rest))
		*rest = ft_strdup(buffer);
	else
		*rest = ft_strjoin_free(*rest, buffer);
}

int				get_next_line(const int fd, char **line)
{
	static t_pos		pos;

	pos.ret = 0;
	if (BUFF_SIZE <= 0 || fd < 0 || !line || read(fd, pos.buffer, 0) < 0)
		return (-1);
	if (!(pos.fd))
		pos.fd = fd;
	if (pos.fd != fd)
	{
		ft_strdel(&(pos.rest));
		pos.fd = fd;
	}
	while ((pos.ret = read(fd, pos.buffer, BUFF_SIZE)))
	{
		add_buffer_to_rest(&(pos.rest), pos.buffer, pos.ret);
		if (pos.rest && ft_strchr(pos.rest, '\n'))
			break ;
	}
	if (pos.ret < BUFF_SIZE && !(ft_strlen(pos.rest)))
		return (0);
	create_line(&(pos.rest), line);
	return (1);
}
