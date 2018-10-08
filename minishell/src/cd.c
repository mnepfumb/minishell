/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:44:06 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/09 11:52:52 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void change_dir(char *args)
{
	char path[BUFF_SIZE];
	char cwd[BUFF_SIZE];
	int pos;

	pos = -1;
	ft_strcpy(path, args);
	getcwd(cwd, sizeof(cwd));
	ft_strcat(cwd, "/");
	ft_strcat(cwd, path);
	ft_strcat(cwd, "/");
	if (chdir(cwd) != 0)
		ft_putstr("Command not found\n");
}

void append_args(char *str1, char *str2)
{
	int i;
	char *dir_name;
	int j;

	j = -1;
	i = -1;
	dir_name = (char*)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	while (str1[++i])
		dir_name[++j] = str1[i];
	dir_name[++j] = ' ';
	i = -1;
	while (str2[++i])
		dir_name[++j] = str2[i];
	dir_name[j] = '\0';
	change_dir(dir_name);
	free(dir_name);
}

void	env_DIR(char **args)
{
	char *path;
	ft_putstr(args[0]);
	if (args[0] == NULL)
	{
		path = getenv_path("HOME");
		if (chdir(path) != 0)
			ft_putstr("Command not found\n");
	}
	else if (ft_strcmp(args[0], "-") == 0)
	{
		path = getenv_path("OLDPWD");
		if (chdir(path) != 0)
			ft_putstr("Command not found\n");
	}
}

void	ft_cd(char **args)
{
	char 	path[BUFF_SIZE];
	char	cwd[BUFF_SIZE];
	char	*env;

	env = getenv_path("PWD");
	if (args[2] != NULL && args[1] != NULL)
		append_args(args[1], args[2]);
	else if (args[1] != NULL)
	{
		ft_strcpy(path, args[1]);
		getcwd(cwd, sizeof(cwd));
		ft_strcat(cwd, "/");
		ft_strcat(cwd, path);
		ft_strcat(cwd, "/");
		if (chdir(cwd) != 0)
			ft_putstr("Command not found\n");
	}
	else if (ft_strcmp(args[0], "cd") == 0)
		env_DIR(args + 1);
	get_env();
	reset_OLDPATH(env);
}
