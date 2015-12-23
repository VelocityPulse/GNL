/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:44:27 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/22 22:55:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# define YOLO ft_putstr("YOLO\n");
# define YOLO1 ft_putstr("YOLO1-\n");
# define YOLO2 ft_putstr("YOLO2--\n");
# define PAUSE while(1){sleep(10000);}

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

#include "libft.h"

int		get_next_line(const int fd, char **line);


#endif


// return 0 if last line
// return 1 if line read
// return -1 if read return -1
