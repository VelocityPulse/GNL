/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:43:33 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/22 15:38:38 by                  ###   ########.fr       */
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

}


int		get_next_line(const int fd, char **line)
{
	static char	*end_chain = NULL;
}
