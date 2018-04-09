/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/09 17:56:06 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		create_line(char **rest, char **line)
{
	char	*tmp;
	// int		i;
	int		j;

	tmp = NULL;
	// i = 0;
	j = 0;
	// while ((*rest)[i] && (*rest)[i] == '\n')
	//  	i++;
	// j = i;
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

static void		add_buffer_to_rest(char **rest, char buffer[])
{
	char	*tmp;

	tmp = NULL;
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
	char		buffer[BUFF_SIZE + 1];
	static char		*rest = NULL;
	int			i;
	int			ret;

	i = 0;
	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		add_buffer_to_rest(&rest, buffer);
		if (rest && ft_strchr(rest + i,'\n'))
			break;
		else
			i += ret;
	}
	if (ret < BUFF_SIZE && !(ft_strlen(rest)))
		return (0);
	 create_line(&rest, line);
	return (1);
}
