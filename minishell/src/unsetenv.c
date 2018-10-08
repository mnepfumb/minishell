/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:46:01 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/09 12:06:32 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*void		reset_env()
{
	extern char **environ;
	int			i;

	i = 0;
	ft_strdel(saved_env);
	while (environ[i])
		i++;
	saved_env = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (environ[++i])
		saved_env[i] = ft_strdup(environ[i]);
}*/

void	ft_del_env(int *check, char **environ, int index)
{
	*check = 1;
	while (environ[index])
	{
		ft_strdel(&environ[index]);
		if (environ[index + 1])
			environ[index] = ft_strdup(environ[index + 1]);
		index++;
	}
}

int		ft_unsetenv(char **args)
{
	int	check;
	int	i;
	int	j;

	i = -1;
	check = 0;
	while (args[++i])
	{
		j = -1;
		while (saved_env[++j])
		{
			if (ft_strncmp(saved_env[j], args[i],
						ft_indexof(saved_env[j], '=')) == 0)
				ft_del_env(&check, saved_env, j);
		}
	}
	return (check);
}
