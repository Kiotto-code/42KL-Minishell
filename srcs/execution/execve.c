/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:44:27 by yichan            #+#    #+#             */
/*   Updated: 2023/08/05 22:54:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_execve(t_book *record, t_cmdl *cmds, char *file, char **env_arr)
{
	if (!file)
	{
		if (cmds->command[0] != NULL)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmds->command[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			g_exit_status = 127;
		}
		exit(g_exit_status);
	}
	else
		execve(file, cmds->command, env_arr);
	(void)record;
}

// void	path_execve(t_book *record, t_cmdl *cmds, char *file, char **env_arr)
// {
// 	// env_arr = env_to_array(record->env);
// 	// file = cmd_path_get(record, cmds->command[0]);
// 	// signal(SIGQUIT, sig_non_interactive_quit);
// 	if (!file)
// 	{
// 		if (access(file, F_OK | X_OK) == 0)
// 			execve(cmds->command[0], cmds->command, env_arr);
// 		else
// 		{
// 			if (cmds->command[0] != NULL)
// 			{
// 				ft_putstr_fd("minishell: ", 2);
// 				ft_putstr_fd(cmds->command[0], 2);
// 				ft_putstr_fd(": command not found\n", 2);
// 				g_exit_status = 127;
// 			}
// 			else
// 				execve(file, cmds->command, env_arr);
// 			exit(g_exit_status);
// 		}
// 	}
// 	else
// 		execve(file, cmds->command, env_arr);
// 	(void)record;
// }