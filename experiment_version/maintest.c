#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int state;
	int temp;

	state = 13;
	temp = 1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((state = get_next_line(fd, &line) > 0))
	{
		printf("state : %d\n", state);
		printf("line : %s\n", line);
		//temp = state;	// La boucle s'execute en fonction du retour de gnl.
		//			state--;	// la boucle force 13 tours.
	}
	close(fd);
	return (0);
}
