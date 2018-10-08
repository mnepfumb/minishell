/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:01:32 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:01:35 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		chr;

	i = 0;
	s = src;
	d = dest;
	chr = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == chr)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
