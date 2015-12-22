#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *str);

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int state;

	state = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (state)
		{
			state = get_next_line(fd, &line); 
			printf("state : %d\n", state);
			printf("line : %s\n", line);
		}
		close(fd);
	}
	return (0);
}
