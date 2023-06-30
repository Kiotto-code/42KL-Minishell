/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:54:15 by yichan            #+#    #+#             */
/*   Updated: 2023/06/30 15:48:15 by yichan           ###   ########.fr       */
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

	if (builtin_checker(cmds->command[0]))
	{
		// builtin_executing(record, cmds);
		// printf("checiiiiiiiing\n");
		if (cmds->fork)
			exit (g_exit_status);
		return ;
	}
	else
	{
		env_arr = env_to_array(record->env);
		file = path_processing(record, cmds->command[0]);
		// printf(RED"file content: %s"DEFAULT, file);
		signal(SIGQUIT, sig_non_interactive_quit);
		if (!file)
		{
			if (access(cmds->command[0], F_OK) == 0)
				execve(cmds->command[0], cmds->command, env_arr);
			else
			{
				if (cmds->command[0] != NULL)
					printf("%s: command not found\n", cmds->command[0]);
				// system("leaks -q minishell");
				exit(0);
			}
		}
		else
			execve(file, cmds->command, env_arr);
		err = errno;
		if (cmds->command[0])
			no_such_message(cmds->command[0]);
		// no_such_message(cmds->command[0]);
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
	if (heredoc_checking(cmds))
		heredoc_processing(cmds);
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
	// printf("check ptr record %p\n", record);
	// printf("check ptr cmds %p\n, sizeof cmds: %lu\n", cmds, sizeof(cmds));

	// printf(RED"cmds->command 0: %s\n"DEFAULT, cmds->command[0]);
	// printf(RED"cmds->command 1: %s\n"DEFAULT, cmds->command[1]);
	if (builtin_checker(cmds->command[0]) 
		&&!cmds->next
		&& cmds->redir)
	{
		executing(record, cmds);
		return ;
	}
	if (pipe_creator(cmds))
		return ;
	while (cmds)
	{
		cmds->pid = fork();
		cmds->fork = 1;
		if (cmds->pid < 0) //unsuccessful fork
			error_msg("bash: fork: Resource temporarily unavailable");
		else if (cmds->pid == 0)
		{
			// sigs_non_interactive_shell();
			// printf("1fork: \n");
			// signal(SIGQUIT, &sig_non_interactive_quit);
			// signal(SIGQUIT, SIG_IGN);
			// signal(SIGQUIT, sig_non_interactive_quit);
			signal(SIGINT, SIG_DFL);
			execute_child_process(record, cmds, begin);
		}
		cmds = cmds->next;
	}
	// printf(RED"pass123\n");
	wait_child_processes(begin);
}
