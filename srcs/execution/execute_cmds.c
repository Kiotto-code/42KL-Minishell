/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:54:15 by yichan            #+#    #+#             */
/*   Updated: 2023/07/09 01:10:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_array(t_env *env)
{
	int		row_count;
	int		i;
	char	**env_arr;

	if (env == NULL)
		return (NULL);
	row_count = env_lstsize(env);
	env_arr = (char **)malloc(sizeof(char *) * (row_count + 1));
	if (!env_arr)
		return (NULL);
	i = 0;
	while (env && (row_count != 0))
	{
		env_arr[i] = ft_strdup(env->var);
		i++;
		row_count--;
		env = env->next;
	}
	env_arr[i] = NULL;
	return (env_arr);
}

/**
 * @brief auto exit the the pipe child fork if builtin in child process.
 * 		command[0] is process if path was passed in.
 * 
 * @param record 
 * @param cmds 
 */
void	executing(t_book *record, t_cmdl *cmds)
{
	char	*file;
	int		err;
	char	**env_arr;

	reset_termios(&record->termios_current);
	if (builtin_checker(cmds->command[0]))
	{
		if (cmds->fork)
			exit (g_exit_status);
		return ;
	}
	else
	{
		env_arr = env_to_array(record->env);
		file = path_processing(record, cmds->command[0]);
		signal(SIGQUIT, sig_non_interactive_quit);
		if (!file)
		{
			if (access(cmds->command[0], F_OK) == 0)
				execve(cmds->command[0], cmds->command, env_arr);
			else
			{
				if (cmds->command[0] != NULL)
					printf("%s: command not found\n", cmds->command[0]);
				exit(0);
			}
		}
		else
			execve(file, cmds->command, env_arr);
		err = errno;
		if (cmds->command[0])
			no_such_message(cmds->command[0]);
		free(file);
		array_liberator(env_arr);
		if (err == 13)
			exit(126);
		else
			exit(127);
	}
}

void	execute_child_process(t_book *record, t_cmdl *cmds, t_cmdl *begin)
{
	fd_opening(cmds);
	// printf("checking heredoc execute 1 \n");
	// if (heredoc_checking(cmds))
	// 	heredoc_processing(cmds);
	// if (heredoc_checking(cmds))
	// 	continue ;
	if (execute_dup2(cmds))
		ft_putendl_fd("dup2 error", 2);
	while (begin->next)
	{
		close(begin->pipe_fd[0]);
		close(begin->pipe_fd[1]);
		begin = begin->next;
	}
	// (void)begin;
	executing(record, cmds);
}

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
		// waitpid(-1, &status, 0);
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
	if (!cmds->next && builtin_checker(cmds->command[0]) && !cmds->redir)
	{
		executing(record, cmds);
		return ;
	}
	if (pipe_creator(cmds))
		return ;
	while (cmds)
	{
		if (heredoc_checking(cmds))
			heredoc_processing(cmds, record->env);
		if (g_exit_status == 1)
			return ;
		cmds = cmds->next;
	}
	cmds = begin;
	while (cmds)
	{
		cmds->pid = fork();
		cmds->fork = 1;
		if (cmds->pid < 0) //unsuccessful fork
			error_msg("bash: fork: Resource temporarily unavailable");
		else if (cmds->pid == 0)
			execute_child_process(record, cmds, begin);
		cmds = cmds->next;
	}
	wait_child_processes(begin);
	if (g_exit_status == 131)
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
}
