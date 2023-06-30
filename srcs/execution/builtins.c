/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:12:45 by yichan            #+#    #+#             */
/*   Updated: 2023/06/17 15:47:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	builtin_executing(t_book *mini, t_cmdl *cmds)
// {
// 	if (!ft_strcmp(cmds->command[0], "cd"))
// 		g_exit_status = cd_executing(mini, cmds->command);
// 	else if (!ft_strcmp(cmds->command[0], "echo"))
// 		g_exit_status = echo_executing(cmds->command);
// 	else if (!ft_strcmp(cmds->command[0], "env"))
// 		g_exit_status = env_executing(mini->env);
// 	else if (!ft_strcmp(cmds->command[0], "exit"))
// 		g_exit_status = exit_executing(mini, cmds->command);
// 	else if (!ft_strcmp(cmds->command[0], "export"))
// 		g_exit_status = export_executing(mini, cmds->command);
// 	else if (!ft_strcmp(cmds->command[0], "pwd"))
// 		g_exit_status = pwd_executing();
// 	else if (!ft_strcmp(cmds->command[0], "unset"))
// 		g_exit_status = unset_executing(mini, cmds->command);
// }

int	builtin_checker(char *command)
{
	if (command == NULL)
		return (0);
	if (!ft_strcmp(command, "cd"))
		return (1);
	if (!ft_strcmp(command, "echo"))
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
	else
		return (0);
}