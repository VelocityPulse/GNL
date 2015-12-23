/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:43:33 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/23 17:56:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int		ft_checkline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static	char	*ft_swapchain(char **s1, char **s2, int mode)
{
	char	*dst;
	char	*temp;

	if (mode == 0)
	{
		if (!*s1)
			return (ft_strdup((char *)s2));
		dst = ft_strjoin(*s1, (char *)s2);
		ft_memdel((void **)s1);
		return (dst);
	}
	else if (mode == 1)
	{
		temp = ft_strsub(*s1, ft_checkline(*s1) + 1, ft_strlen(*s1));
		ft_memdel((void **)s1);
		return (temp);
	}
	dst = ft_strjoin(*s1, *s2);
	ft_memdel((void **)s1);
	ft_memdel((void **)s2);
	return (dst);
}

static int		ft_capture(const int fd, char **line, char **end_chain)
{
	char	buff[BUFF_SIZE];
	char	*capture;
	int		ret;
	int		i;

	capture = NULL;
	ret = 1;
	while (ft_strchr(buff, '\n') == NULL && ret != 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		capture = ft_swapchain(&capture, (char **)&buff, 0);
	}
	ft_memdel((void **)end_chain);
	YOLO2
	if ((i = ft_checkline(capture)) < (int)ft_strlen(capture))
		*end_chain = ft_strdup(&capture[i + 1]);
	*line = ft_strsub(capture, 0, i);
	ft_memdel((void **)&capture);
	if (!*end_chain && ret < BUFF_SIZE)
		return (0);
	return (1);
}


int		get_next_line(const int fd, char **line)
{
	static char	*end_chain = NULL;
	char		*temp;
	char		*temp2;
	int			i;
	int			state;

	ft_memdel((void **)line);
	if (!end_chain)
		return (ft_capture(fd, line, &end_chain));
	if ((i = ft_checkline(end_chain)) < (int)ft_strlen(end_chain))
	{
		ft_memdel((void **)line);
		*line = ft_strsub(end_chain, 0, i);
		end_chain = ft_swapchain(&end_chain, NULL, 1);
		if (end_chain[0])
			return (1);
		return (0);
	}
	temp = ft_strdup(end_chain);
	state = ft_capture(fd, line, &end_chain);
	*line = ft_swapchain(&temp, line, 2);
	return (state);
}
