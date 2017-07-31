/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:11:29 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/30 18:36:33 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	run_cmd(char **cmd)
{
	extern char	**environ;
	int			pid;
	int			child_stat;

	pid = fork();
	if (pid == 0)
		execve(cmd[0], cmd, environ);
	else if (pid < 0)
		ft_putstr_fd("Error forking new process\n", 2);
	else
	{
		while (!WIFEXITED(child_stat) && !WIFSIGNALED(child_stat))
			waitpid(pid, &child_stat, WUNTRACED);
	}
}

void	ft_echo(char **line)
{
	int		i;
	int		x;

	i = 1;
	x = 0;
	while (line[i])
	{
		x = 0;
		while (line[i][x])
		{
			if (line[i][x] != '"')
				ft_putchar(line[i][x]);
			else
				break ;
			x++;
		}
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	run_ls(char **cmd)
{
	extern char	**environ;
	int			pid;
	int			child_stat;

	pid = fork();
	if (pid == 0)
		execve("/bin/ls", cmd, environ);
	else if (pid < 0)
		ft_putstr_fd("Error forking new process\n", 2);
	else
	{
		waitpid(pid, &child_stat, WUNTRACED);
		while (!WIFEXITED(child_stat) && !WIFSIGNALED(child_stat))
			waitpid(pid, &child_stat, WUNTRACED);
	}
}

void	ft_cd(char **args)
{
	if (args[0] == NULL)
		ft_putstr_fd("Error forking new process\n", 2);
	else
	{
		if (args[1] != NULL)
		{
			chdir(args[1]);
		}
		else
			chdir(args[0]);
	}
}
