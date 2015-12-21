#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *str);

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i;

	i = 2;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (i)
		{
			printf("\n\n--------\nreturn GNL : %d\n", get_next_line(fd, &line));
			printf("line : %s\n", line);
			i--;
		}
		close(fd);
	}
	return (0);
}
