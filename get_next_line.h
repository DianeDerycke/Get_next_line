/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:18:12 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/04/10 14:27:37 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_pos
{
	int					fd;
	char				*rest;
	struct s_pos		*next;
}					t_pos;

int		get_next_line(const int fd, char **line);

#endif
