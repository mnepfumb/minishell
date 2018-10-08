/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:42:12 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 11:42:22 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t length)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	int					index;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	index = 0;
	while ((str1[index] != '\0' || str2[index] != '\0') && length > 0)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
		length--;
	}
	return (0);
}
