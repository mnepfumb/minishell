/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:06:46 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:06:49 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *d;

	d = (char*)malloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	d = ft_strcpy(d, s);
	return (d);
}
