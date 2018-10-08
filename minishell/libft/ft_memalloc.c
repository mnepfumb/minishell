/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:01:12 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:01:15 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!size)
		return (NULL);
	mem = malloc(sizeof(void) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
