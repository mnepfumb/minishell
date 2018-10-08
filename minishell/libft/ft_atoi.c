/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:49:51 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/08/07 16:00:57 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *src)
{
	int		i;
	long	done;
	int		flag;

	i = 0;
	done = 0;
	while (src[i] == ' ' || (src[i] >= '\t' && src[i] <= '\r'))
		i++;
	if (src[i] == '-')
		flag = -1;
	else
		flag = 1;
	if (src[i] == '+' || src[i] == '-')
		i++;
	while (src[i] != '\0' && src[i] > 47 && src[i] < 58)
	{
		done = ((done * 10) + src[i]) - '0';
		i++;
	}
	done = done * flag;
	return (done);
}
