/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:06:53 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/30 18:37:49 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	mainloop(void)
{
	char	buffer[BUFF_SIZE + 1];
	char	**command;

	while (1)
	{
		ft_putstr(PROMPT);
		ft_bzero(buffer, BUFF_SIZE + 1);
		read(0, buffer, BUFF_SIZE);
		command = ft_strsplit(ft_strtrim(buffer), ' ');
		if (*command != NULL)
		{
			if (ft_strcmp(command[0], "exit") == 0)
				return ;
			else if (ft_strcmp(command[0], "ls") == 0)
				run_ls(command);
			else if (ft_strcmp(command[0], "echo") == 0)
				ft_echo(command);
			else if (ft_strcmp(command[0], "cd") == 0)
				ft_cd(command);
			else
				run_cmd(command);
		}
	}
}

int		main(void)
{
	mainloop();
	return (0);
}
