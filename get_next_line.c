/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:43:33 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/23 12:20:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static	char	*ft_swapchain(char *s1, char *s2)
{
	char	*dst;

	if (!s1)
		return (ft_strdup(s2));
	dst = ft_strjoin(s1, s2);
	ft_memdel((void **)&s1);
	return (dst);
}

static int		ft_capture(const int fd, char **line, char **end_chain)
{
	char	*buff;
	char	*capture;
	int		ret;
	int		i;

	capture = NULL;
	ret = 1;
	buff = (char *)ft_memalloc(BUFF_SIZE);
	while (ft_strchr(buff, '\n') == NULL && ret != 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		{
			ft_memdel((void **)&buff);
			return (-1);
		}
		capture = ft_swapchain(capture, buff);
	}
	ft_memdel((void **)end_chain);
	if ((i = ft_checkline(capture)) < ft_strlen(capture))
		*end_chain = ft_strdup(&capture[i + 1]);
//	ft_putstr(capture); ft_putchar(' ');
	*line = ft_strsub(capture, 0, i);
	if (end_chain[0])
		return (1);
	return (0);
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
	if ((i = ft_checkline(end_chain)) < ft_strlen(end_chain))
	{
		ft_memdel((void **)line);
		*line = ft_strsub(end_chain, 0, i);
		end_chain = &end_chain[i + 1];
		if (end_chain[0])
			return (1);
		return (0);
	}
	temp = ft_strdup(end_chain);
	state = ft_capture(fd, line, &end_chain);
	temp2 = ft_strdup(*line);
	ft_memdel((void **)line);
	*line = ft_strjoin(temp, temp2);
	return (state);
}
