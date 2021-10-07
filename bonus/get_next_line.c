/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:36:18 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:36:20 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*check_remain(char **remains, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (*remains)
	{
		p_n = ft_strchr(*remains, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(*remains);
			ft_strcpy(*remains, ++p_n);
		}
		else
		{
			*line = ft_strdup(*remains);
			free(*remains);
			*remains = NULL;
		}
	}
	else
		*line = ft_strnew(BUFF_SIZE);
	return (p_n);
}

char	*get_line(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	return (*line);
}

int	get_next_line(int fd, char **line)
{
	static char	*remains;
	char		buf[BUFF_SIZE + 1];
	int			bytes_was_read;
	char		*p_n;

	if (!line || BUFF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	p_n = check_remain(&remains, line);
	while (!p_n)
	{
		bytes_was_read = read(fd, buf, BUFF_SIZE);
		if (bytes_was_read <= 0)
			return (bytes_was_read);
		buf[bytes_was_read] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			remains = ft_strdup(++p_n);
		}
		*line = get_line(line, buf);
	}
	return (1);
}
