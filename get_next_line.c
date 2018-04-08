/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:16 by dideryck          #+#    #+#             */
/*   Updated: 2018/04/08 19:44:13 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		create_line(char **rest, char **line)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 0;
	j = 0;
	if ((*rest)[i] && (*rest)[i] == '\n')
	 	i++;
	j = i;
	while ((*rest)[j] && (*rest)[j] != '\n')
		j++;
	// printf("J VAUT %d\n", j);
		*line = ft_strndup(*rest + i, j);
	// if (j)
	// 	j--;
	// printf("J AFTER %d\n", j);
	// if ((*rest)[j + 1] && (*rest)[j + 1] == '\n')
		// j++;
	// printf("J AFTER THE AFTER %d\n", j);
	// printf("REST + I + J %s", *rest + i + j);
	// printf("I + J =>%d", i + j);
	tmp = ft_strdup(*rest + j);
	ft_strdel(rest);
	*rest = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static void		add_buffer_to_rest(char **rest, char buffer[])
{
	char	*tmp;

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

	i = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	while ((i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		// printf("VALUE I ==> %d\n", i);
		buffer[i] = '\0';
		add_buffer_to_rest(&rest, buffer);
		if (ft_strchr(rest,'\n'))
		{
			// printf("%s\n", "LAAA");
			create_line(&rest, line);
			return (1);
		}
	}
	if (i < 0)
		return (-1);
	if (rest && *rest && !*line)
	{
		// printf("REST IS =>%s\n", rest);
		create_line(&rest, line);
	}
	return (*rest && (*line)[0] != '\0' ? 1 : 0);
}