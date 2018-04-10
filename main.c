/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:47:20 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/04/10 18:33:19 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		count;

	count = 1;
	line = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	(void)argc;

	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
