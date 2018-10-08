/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:45:10 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/09 09:18:04 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		parse_command(char **command)
{
	if (command[0] != NULL)
	{
		if (ft_strcmp(command[0], "exit") == 0)
			ft_exit_mini();
		else if (ft_strcmp(command[0], "echo") == 0)
			ft_echo(command);
		else if (ft_strcmp(command[0], "cd") == 0)
			ft_cd(command);
		else if (ft_strcmp(command[0], "env") == 0)
			print_env();
		else if (ft_strcmp(command[0], "setenv") == 0)
			ft_setenv(command + 1);
		else if (ft_strcmp(command[0], "unsetenv") == 0)
			ft_unsetenv(command + 1);
		else
			if (search_paths(command) > 0)
				ft_putstr("Command not found\n");
	}
	else
		ft_putstr("There is no command to run\n");
}

int			find_builtin(char **command)
{
	if (ft_strstr(command[0], "/"))
	{
		run_bin(command);
		return (-1);
	}
	return (0);
}

void		get_prompt()
{
	ft_putstr("\033[1;34mMASH ");
	ft_putstr("\33[1m\033[31m");
	ft_putstr(PROMPT);
	ft_putstr("\033[0;33m");
}

int			main(void)
{
	char	buffer[BUFF_SIZE + 1];
	char	**command;

    header();
	get_env();
	while (1)
	{
		get_prompt();
		signal(SIGINT, signal_handler);
		ft_bzero(buffer, BUFF_SIZE + 1);
		read(0, buffer, BUFF_SIZE);
		command = ft_strsplit(ft_strtrim(buffer), ' ');
		if (!find_builtin(command))
			parse_command(command);
	}
	return (0);
}
