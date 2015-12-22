/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:43:33 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/22 01:14:50 by                  ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_memdel(void **ap);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strcat(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);

static int		ft_checkline(char *buff)
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

static	char	*ft_swapchain(char *capture, char *buff)
{
	char	*dst;

	if (!capture)
		return (ft_strdup(buff));
	dst = ft_strjoin(capture, buff);
	free(capture);
	return (dst);
}

static int		ft_capture(const int fd, char **line, char **end_chain)
{
	int		ret;
	char	*buff;
	char	*capture;
	int		i;

	ret = BUFF_SIZE;
	capture = NULL;
	buff = (char *)ft_memalloc(BUFF_SIZE + 1);
	while (!(ft_strstr(buff, "\n")) && ret == BUFF_SIZE)
	{
		ft_bzero(buff, BUFF_SIZE);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		capture = ft_swapchain(capture, buff);
		// ok
	}
	free(buff);
	if (end_chain != NULL)
		ft_memdel((void *)end_chain);
	if (capture[ft_checkline(capture) + 1])
	{
		*end_chain = ft_strdup(&capture[ft_checkline(capture) + 1]);
		end_chain[0][ft_strlen(&capture[ft_checkline(capture) + 1])] = 0;
	}
	*line = ft_strdup(ft_strsub(capture, 0, ft_checkline(capture)));
	free(capture);
	if (ret < BUFF_SIZE)
		return(0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*end_chain = NULL;
	char		*temp;
	char		**chain;
	int			i;
	int			state;

	if (end_chain == NULL)
		return (ft_capture(fd, line, &end_chain));
	else
	{
		if ((i = ft_checkline(end_chain)) < ft_strlen(end_chain))
		{
			ft_memdel((void **)line);
			*line = ft_strdup(ft_strsub(end_chain, 0, i));
			end_chain = &end_chain[i];
			return (1);
		}
		else
		{
			temp = ft_strdup(end_chain);
			state = ft_capture(fd, chain, &end_chain);
			*line = ft_strjoin(temp, *chain);
			return (state);
		}
	}
}
