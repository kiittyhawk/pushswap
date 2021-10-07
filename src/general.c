/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:04 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:05 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	is_large(char *nmb)
{
	int		i;
	int		len;
	char	*nmb_max;
	char	*nmb_min;

	i = 0;
	len = ft_strlen(nmb);
	nmb_max = "2147483647";
	nmb_min = "-2147483648";
	while (nmb[0] == '-' && len >= 11 && nmb[i])
	{
		if (nmb[i + 1] > nmb_min[i + 1] || len > 11)
			send_message(2);
		i++;
	}
	while (nmb[0] != '-' && len >= 10 && nmb[i])
	{
		if (nmb[i] > nmb_max[i] || len > 10)
			send_message(2);
		i++;
	}
}
