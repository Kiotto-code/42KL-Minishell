/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:12:45 by yichan            #+#    #+#             */
/*   Updated: 2023/08/14 00:36:18 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_executing(t_book *mini, t_cmdl *cmds)
{
	if (!ft_strcmp(cmds->command[0], "cd"))
		g_exit_status = ms_cd(&mini->env, &mini->export, cmds->command[1]);
	else if (!ft_strcmp(cmds->command[0], "echo") || \
		!ft_strcmp(cmds->command[0], "ECHO"))
		g_exit_status = ms_echo(cmds->command);
	else if (!ft_strcmp(cmds->command[0], "env"))
		g_exit_status = ms_env(mini->env);
	else if (!ft_strcmp(cmds->command[0], "export"))
		g_exit_status = ms_export(&mini->env, &mini->export, cmds->command);
	else if (!ft_strcmp(cmds->command[0], "unset"))
		g_exit_status = ms_unset(&mini->env, &mini->export, cmds->command);
	else if (!ft_strcmp(cmds->command[0], "pwd"))
		g_exit_status = ms_pwd(mini->env);
	else if (!ft_strcmp(cmds->command[0], "exit"))
		g_exit_status = ms_exit(mini, cmds->command);
	else if (!ft_strcmp(cmds->command[0], "credits"))
		g_exit_status = credit();
	if (cmds->fork)
		exit (g_exit_status);
	return ;
}

int	builtin_checker(char *command)
{
	if (command == NULL)
		return (0);
	if (!ft_strcmp(command, "cd"))
		return (1);
	if (!ft_strcmp(command, "echo") || !ft_strcmp(command, "ECHO"))
		return (1);
	if (!ft_strcmp(command, "env"))
		return (1);
	if (!ft_strcmp(command, "exit"))
		return (1);
	if (!ft_strcmp(command, "export"))
		return (1);
	if (!ft_strcmp(command, "pwd"))
		return (1);
	if (!ft_strcmp(command, "unset"))
		return (1);
	if (!ft_strcmp(command, "credits"))
		return (1);
	else
		return (0);
}
