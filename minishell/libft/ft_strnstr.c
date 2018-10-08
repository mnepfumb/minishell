/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:09:32 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:09:35 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hy, const char *needle, size_t len)
{
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(needle);
	if (len2 == 0)
		return ((char*)hy);
	while (hy[i] && len2 <= len--)
	{
		if (ft_memcmp(hy + i, needle, len2) == 0)
			return ((char *)hy + i);
		i++;
	}
	return (NULL);
}
