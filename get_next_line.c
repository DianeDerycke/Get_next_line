/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/04 00:12:51 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_build_line(char **tmp, char **line, char **newtmp)
{
	int		i;

	i = 0;
	while ((*tmp)[i] && (*tmp)[i] != '\n')
		i++;
	// printf("%d\n", i);
	if (i)
		*line = ft_strndup(*tmp, i);
	else
		*line = ft_strdup("");
	*newtmp = ft_strdup(ft_strchr(*tmp, '\n'));
	ft_strdel(tmp);
	if (*newtmp && **newtmp == '\n')
		*tmp = ft_strdup((*newtmp) + 1);
	ft_strdel(newtmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static char		*tmp;
	char			*newtmp;
	int				i;

	i = 1;
	while (i)
	{
		if (!line || fd < 0 || ((i = read(fd, buffer, BUFF_SIZE)) < 0))
			return (-1);
		if (i)
			buffer[i] = '\0';

		if (tmp && ft_strchr(tmp, '\n'))
			break ;
		if (!tmp)
			tmp = ft_strdup(buffer);
		else
		{
			newtmp = ft_strjoin(tmp, buffer);
			buffer[0] = (i == 0 ? '\0' : 0);
			ft_strdel(&tmp);
			tmp = newtmp;
		}
	}
	ft_build_line(&tmp, line, &newtmp);
	return (buffer[0] ? 1 : 0);
}
