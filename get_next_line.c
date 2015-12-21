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
char	*ft_strstr(const char *s1, char *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s1, int c);

int		ft_checkline(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_swapchain(char *buff)
{
	char	*dst;

	dst = (char *)ft_memalloc(ft_strlen(buff) + BUFF_SIZE);
	dst = ft_strcpy(dst, buff);
	return (dst);
}

int		ft_capture(const int fd, char **line, char **end_chain)
{
	int		ret;
	char	*buff;
	char	*capture;
	int		slash_n;

	buff = (char *)ft_memalloc(BUFF_SIZE);
	while (!(ft_strstr(buff, "\n")))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		capture = ft_swapchain(buff);
	}
	free(buff);
	*end_chain = ft_strdup(ft_strchr(capture, '\n'));
	*line = ft_strdup(ft_strsub(capture, 0, ft_checkline(capture)));
	free(capture);
	if (ret < BUFF_SIZE)
		return(0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*end_chain = NULL;
	char		*chain;

}
