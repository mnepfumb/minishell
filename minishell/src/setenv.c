/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:45:28 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/09 12:04:41 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*replace_env(int *check, char *command, char *saved_env)
{
	char	*temp;

	*check = 1;
	free(saved_env);
	saved_env = NULL;
	temp = ft_strdup(command);
	return (temp);
}

void		free_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env);
	env[i] = NULL;
}

char		**add_env(char *command)
{
	char	**temp;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (saved_env[len] != 0)
		len++;
	temp = (char**)malloc(sizeof(char*) * (len + 2));
	temp[len + 1] = 0;
	while (++i < len)
		temp[i] = ft_strdup(saved_env[i]);
	temp[len] = ft_strdup(command);
	free_env(saved_env);
	return (temp);
}

void		ft_setenv(char **command)
{
	int		i;
	int		pos;
	int		j;

	j = -1;
	i = -1;
	while (command[++i])
	{
		pos = 0;
		if (ft_strchr(command[i], '=') != NULL)
		{
			while (saved_env[++j] != 0)
			{
				if ((ft_strncmp(saved_env[j], command[i],
								ft_indexof(command[i], '='))) == 0)
					saved_env[j] = replace_env(&pos, command[i], saved_env[j]);
			}
			if (!pos)
				saved_env = add_env(command[i]);
		}
	}
}
