/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:59:58 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/24 15:00:02 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*track;
	t_list		*tracked;

	if (!alst || !*alst)
		return ;
	tracked = *alst;
	while (tracked)
	{
		track = tracked->next;
		ft_lstdelone(&tracked, del);
		tracked = track;
	}
	*alst = NULL;
}
