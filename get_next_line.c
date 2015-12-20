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

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
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
	int		ret;
	int		i;

	i = 0;
	line = NULL;
	buff = (char *)ft_memalloc(BUFF_SIZE);
	while (1)
	{
		ret = read(fd, buff, BUFF_SIZE);
		
	}
	return (&buff[0]);
}

int		get_next_line(const int fd, char **line)
{
	static char	*end_chain;
	char		*

	end_chain = NULL;
	if )
	return (ft_capture(fd));
}
