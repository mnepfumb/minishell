/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:05:05 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:05:07 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int counter;

	counter = 0;
	if (s != NULL)
	{
		while (s[counter] != '\0')
		{
			ft_putchar(s[counter]);
			counter++;
		}
	}
}
