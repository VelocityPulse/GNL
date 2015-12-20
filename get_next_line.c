/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:43:33 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/18 14:43:49 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memalloc(size_t size);
int		ft_strlen(char *src);
char	*ft_strcpy(char *dst, const char *src);

int		ft_checkline(char *buff)
{
	int i;

}

char	*ft_swapchain(char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen(src);
	dst = (char *)ft_memalloc(len + BUFF_SIZE);
	dst = ft_strcpy(dst, src);
	return (dst);
}

char	*ft_capture(const int fd)
{
	char	*buff;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	line = NULL;
	buff = (char *)ft_memalloc(BUFF_SIZE);
	while (1)
	{
		ret = read(fd, buff, BUFF_SIZE);
		line = ft_swapchain(buff);
		if (ft_checkline(line))
			return (ft_cutend(line));
	}
	return (&buff[0]);
}

int		get_next_line(const int fd, char **line)
{
	return (ft_capture(fd));
}
