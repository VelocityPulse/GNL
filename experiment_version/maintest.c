/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:47:36 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 14:49:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int state;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((state = get_next_line(fd, &line) > 0))
	{
		printf("line : %s\n", line);
		printf("state : %d\n\n", state);
	}
//	printf("state for fd 454 : %d\n", get_next_line(454, &line));
	close(fd);
	return (0);
}
