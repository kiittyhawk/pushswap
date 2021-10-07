/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:38:09 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:38:10 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	s;
	size_t			i;

	str = (unsigned char *)b;
	s = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = s;
		i++;
	}
	return (str);
}
