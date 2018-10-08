/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 14:17:46 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/08/07 16:13:05 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_nbr(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				size;
	unsigned int	nbr;

	size = ft_cnt_nbr(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		size++;
	}
	if (!(str = ft_strnew((size_t)size)))
		return (NULL);
	str[--size] = nbr % 10 + '0';
	while (nbr /= 10)
		str[--size] = nbr % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
