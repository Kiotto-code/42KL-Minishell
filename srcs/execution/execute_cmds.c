/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:54:15 by yichan            #+#    #+#             */
/*   Updated: 2023/08/05 23:31:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief auto exit the the pipe child fork if builtin in child process.
 * 		command[0] is process if path was passed in.
 * 
 * @param record 
 * @param cmds 
 */
void	executing(t_book *record, t_cmdl *cmds)
{
	char	**env_arr;
	char	*file;

	reset_termios(&record->termios_current);
	if (builtin_checker(cmds->command[0]))
		builtin_executing(record, cmds);
	else
	{
		env_arr = env_to_array(record->env);
		file = cmd_path_get(record, cmds->command[0]);
		path_execve(record, cmds, file, env_arr);
		if (access(cmds->command[0], F_OK | X_OK) == 0)
			errno = 21;
		if (access(cmds->command[0], F_OK) == 0 && cmds->command[0][0] == '/')
			errno = 21;
		if (cmds->command[0])
			no_such_file_or_dir(cmds->command[0]);
		ft_free(file);
		array_liberator(env_arr);
		if (errno == 21 || errno == 13)
			exit(126);
		else
			exit(127);
	}
}

void	execute_child_process(t_book *record, t_cmdl *cmds, t_cmdl *begin)
{
	fd_opening(cmds);
	if (execute_dup2(cmds))
		ft_putendl_fd("dup2 error", 2);
	while (begin->next)
	{
		close(begin->pipe_fd[0]);
		close(begin->pipe_fd[1]);
		begin = begin->next;
	}
	executing(record, cmds);
}

/**
 * @brief 	WTERMSIG: Determine which signal caused the child process to exit
 * 			WIFSIGNALED: is true of status , this macro returns the signal
 * 						number of the signal that terminated the child process
 * 
 * @param begin 
 */
void	wait_child_processes(t_cmdl *begin)
{
	t_cmdl	*cmd;
	int		status;

	status = 0;
	cmd = begin;
	while (begin->next)
	{
		close(begin->pipe_fd[0]);
		close(begin->pipe_fd[1]);
		begin = begin->next;
	}
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		g_exit_status = WEXITSTATUS(status);
		if (!g_exit_status && WIFSIGNALED(status))
			g_exit_status = 128 + WTERMSIG(status);
		cmd = cmd->next;
	}
}

void	execute_cmds(t_book *record, t_cmdl *cmds)
{
	t_cmdl	*begin;

	begin = cmds;
	if (pre_execv(record, cmds) == 1)
		return ;
	signal(SIGQUIT, sig_non_interactive_quit);
	while (cmds)
	{
		cmds->pid = fork();
		cmds->fork = 1;
		if (cmds->pid < 0)
			error_msg("bash: fork: Resource temporarily unavailable");
		else if (cmds->pid == 0)
			execute_child_process(record, cmds, begin);
		cmds = cmds->next;
	}
	wait_child_processes(begin);
}
