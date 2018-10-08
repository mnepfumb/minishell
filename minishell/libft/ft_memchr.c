/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:01:42 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:01:45 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	chr;

	i = 0;
	src = (unsigned char*)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == chr)
		{
			return (src + i);
		}
		i++;
	}
	return (NULL);
}
