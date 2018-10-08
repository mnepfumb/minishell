/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:44:22 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/09/09 09:24:11 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		echo_string(char *str)
{
	int len;
	int start;
	int end;

	len = (int)ft_strlen(str);
	start = 0;
	end = len - 1;
	if (str[0] == '$')
	{
		ft_putstr("\033[0;32m");
		ft_putstr(getenv_path(&str[1]));
	}
	else
	{
		while (str[start] == '\'' || str[start] == '"')
			start++;
		while (str[end] == '\'' || str[end] == '"')
			end--;
		while (start <= end)
		{
			ft_putstr("\033[0;32m");
			ft_putchar(str[start++]);
		}
	}
}

void	ft_echo(char **line)
{
	int i;

	i = 0;
	if (!line[0])
		ft_putchar('\n');
	while (line[++i])
	{
		echo_string(line[i]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
