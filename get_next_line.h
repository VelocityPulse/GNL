/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:44:27 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/23 19:29:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000
# define YOLO ft_putstr("\nYOLO\n");
# define YOLO1 ft_putstr("\nYOLO1-\n");
# define YOLO2 ft_putstr("\nYOLO2--\n");
# define PAUSE while(1){sleep(1000);}
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
