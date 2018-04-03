#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	// i = 0;

	// while (i != 117718)
	// {
	// 	write(1, &i, 1);
	// 	write(1, "\n", 1);
	// 	i++;
	// }


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
