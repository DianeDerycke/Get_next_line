#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	// int		j;

	// i = 0;
	// j = 0;

	// while (i != 240000)
	// {
	// 	if (j == 9)
	// 		j = 0;
	// 	ft_putnbr(j);
	// 	ft_putchar('\n');
	// 	i++;
	// 	j++;
	// }


	line = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	(void)argc;
	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		printf("%s%d\n","VALUE I =====> ", i );
		free(line);
	}
	return (0);
}
