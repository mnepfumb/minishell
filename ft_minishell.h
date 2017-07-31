/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:37:57 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/07/30 18:35:58 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
#define FT_MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFF_SIZE 1024
#define PROMPT "$> "

int     main(void);
void	mainloop(void);
void	run_ls(char **cmd);
void	ft_echo(char **line);
void	run_cmd(char **cmd);
void	ft_cd(char **args);

#endif
