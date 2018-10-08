/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:45:41 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/08 12:39:49 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		signal_c(int signum)
{
	(void)signum;
	if (g_pid > 0)
	{
		ft_putchar('\n');
		signal(g_pid, signal_c);
	}
	else
		ft_putstr("\nUse exit command to quit\n");
}

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		get_prompt();
		signal(SIGINT, signal_handler);
	}
}

