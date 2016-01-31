/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:48:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/31 13:11:35 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_strncpy(ft_strnew(i), str, i);
	line[i] = 0;
	return (line);
}

static char		*ft_end_chain(char *str)
{
	int		i;
	char	*end_chain;

	i = 0;
	end_chain = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	end_chain = ft_strdup(&str[i + 1]);
	if (i == (int)ft_strlen(str))
		ft_memdel((void **)&end_chain);
	ft_memdel((void **)&str);
	return (end_chain);
}

static int		ft_alloc_gnl(char **save, t_gnl *g)
{
	if (!(g->buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!*save)
	{
		if (!(*save = ft_strnew(1)))
			return (-1);
	}
	return (1);
}

static int		ft_gnl_read(int fd, char **save, t_gnl *g)
{
	g->find = 1;
	if ((g->ret = read(fd, g->buff, BUFF_SIZE)) == -1)
		return (-1);
	g->buff[g->ret] = 0;
	g->temp = *save;
	*save = ft_strjoin(*save, g->buff);
	ft_memdel((void **)&g->temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	t_gnl		g;

	if (((g.ret = 42)) && (ft_alloc_gnl(&save, &g) == -1))
		return (-1);
	while (!(ft_strchr(save, '\n')) && g.ret > 0)
	{
		if (ft_gnl_read(fd, &save, &g) == -1)
			return (-1);
	}
	if ((ft_strchr(save, '\n') == &save[ft_strlen(save) - 1]) && !(g.find = 0))
	{
		if (ft_gnl_read(fd, &save, &g) == -1)
			return (-1);
	}
	ft_memdel((void **)&g.buff);
	*line = ft_get_line(save);
	save = ft_end_chain(save);
	if ((g.ret == 0 && !save) || (g.ret == 0 && g.find == 1))
	{
		ft_memdel((void **)&save);
		return (0);
	}
	return (1);
}
