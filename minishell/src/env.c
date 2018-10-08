/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:44:34 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/09 11:53:12 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		print_env(void)
{
	int		i;

	i = -1;
	while (saved_env[++i])
	{
		ft_putstr("\033[0;32m");
		ft_putstr(saved_env[i]);
		ft_putchar('\n');
	}
}

void		get_env()
{
	extern char **environ;
	int		i;

	i = 0;
	while (environ[i])
		i++;
	saved_env = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (environ[++i])
		saved_env[i] = ft_strdup(environ[i]);
}

void		reset_OLDPATH(char *oldpwd)
{
	char	*path;
	int		i;
	char	new_pwd[BUFF_SIZE];
	int		pos;

	pos = 0;
	i = -1;	
	path = "OLDPWD=";
	ft_strcpy(new_pwd, path);
	ft_strcat(new_pwd, oldpwd);
	while (saved_env[++i] != 0)
	{
		if ((ft_strncmp(saved_env[i], new_pwd, ft_indexof(new_pwd, '='))) == 0)
		   saved_env[i] = replace_env(&pos, new_pwd, saved_env[i]);	
	}
}
