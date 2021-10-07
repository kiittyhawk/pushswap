/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:36:45 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:36:47 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# define BUFF_SIZE 1

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dest, char *src);
void	*ft_bzero(void *s, size_t n);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
char	*check_remain(char **remains, char **line);
size_t	ft_strlen(const char *s);
char	*get_line(char **line, char *buf);

#endif