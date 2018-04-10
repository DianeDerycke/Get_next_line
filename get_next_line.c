/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/10 15:15:28 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		create_line(t_pos *pos, char **line)
{
	char	*tmp;
	int		j;

	tmp = NULL;
	j = 0;
	while (pos->buffer[j] && pos->buffer[j] != '\n')
		j++;
	tmp = ft_strndup(pos->buffer, j);
	*line = ft_strjoin(*line, tmp);
	ft_strdel(&tmp);
	pos->rest = ft_strdup(pos->buffer + j);
	// while ((*rest)[j] && (*rest)[j] != '\n')
	// 	j++;

	// *line = ft_strndup(*rest, j);
	// if ((*rest)[j] && (*rest)[j] == '\n')
	// 	j++;
	// if ((*rest)[j])
	// {
	// 	tmp = ft_strdup(*rest + j);
	// 	ft_strdel(rest);
	// 	*rest = ft_strdup(tmp);
	// 	ft_strdel(&tmp);		
	// }
	// else
	// {
	// 	free(*rest);
	// 	*rest = ft_strdup("");
	// }

}

// static void		add_buffer_to_rest(char **rest, char buffer[], int ret)
// {
// 	char	*tmp;

// 	tmp = NULL;
// 	buffer[ret] = '\0';
// 	if (!(*rest))
// 		*rest = ft_strdup(buffer);
// 	else
// 	{
// 		tmp = ft_strjoin(*rest, buffer);
// 		ft_strdel(rest);
// 		*rest = ft_strdup(tmp);
// 		ft_strdel(&tmp);
// 	}
// }

int		get_next_line(const int fd, char **line)
{
	static t_pos		pos;

	pos.ret = 0;
	*line = ft_strnew(1);
	if (fd < 0 || !line || read(fd, pos.buffer, 0) < 0)
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
		// add_buffer_to_rest(&(pos.rest), buffer, ret);
		if (ft_strchr(pos.buffer,'\n'))
			break;
		*line = ft_strjoin(*line, pos.buffer);
	}
	if (pos.ret == 0 && (!(ft_strlen(*line))) && !(ft_strlen(buffer)))
		return (0);
	if (pos.ret != 0)
		create_line(&pos, line);
	return (1);
}
