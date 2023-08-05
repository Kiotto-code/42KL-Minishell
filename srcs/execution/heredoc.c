/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:12:59 by yichan            #+#    #+#             */
/*   Updated: 2023/08/06 00:21:46 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_heredoc(t_book *record, t_cmdl *cmd, char *stop, t_env *env)
{
	char		*input;
	char		*buffer;

	input = NULL;
	buffer = malloc(sizeof(char *) * 1024);
	while (1)
	{
		input = readline("> ");
		if (input == NULL)
		{
			cursor_plc(1);
			break ;
		}
		if (!ft_strncmp(input, stop, ft_strlen(stop) + 1))
			break ;
		here_xpnd(record, &input);
		ft_putendl_fd(input, cmd->out);
		ft_free(input);
	}
	close(cmd->out);
	exit(g_exit_status);
	(void)(env);
}

void	heredoc_fork(t_book *record, t_cmdl *cmd, t_redir *tmp, int *fd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig_interrupt_here);
		signal(SIGTERM, SIG_DFL);
		close(fd[0]);
		cmd->out = fd[1];
		execute_heredoc(record, cmd, tmp->name, record->env);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		cmd->in = fd[0];
	}
}

void	heredoc_processing(t_book *record, t_cmdl *cmd)
{
	int		fd[2];
	t_redir	*tmp;

	tmp = cmd->redir;
	while (tmp && ft_strcmp("<<", tmp->type) == 0)
	{
		if (pipe(fd) < 0)
		{
			perror("Error");
			g_exit_status = 1;
			break ;
		}
		heredoc_fork(record, cmd, tmp, fd);
		tmp = tmp->next;
	}
}

// void	heredoc_processing(t_book *record, t_cmdl *cmd)
// {
// 	int		fd[2];
// 	// int		pid;
// 	t_redir	*tmp;
// 	// int		status;

// 	tmp = cmd->redir;
// 	while (tmp && ft_strcmp("<<", tmp->type) == 0)
// 	{
// 		if (pipe(fd) < 0)
// 		{
// 			perror("Error");
// 			g_exit_status = 1;
// 			break ;
// 		}
// 		heredoc_fork(record, cmd, tmp, fd);
// 		// pid = fork();
// 		// if (pid == 0)
// 		// {
// 		// 	signal(SIGINT, sig_interrupt_here);
// 		// 	signal(SIGTERM, SIG_DFL);
// 		// 	close(fd[0]);
// 		// 	cmd->out = fd[1];
// 		// 	execute_heredoc(record, cmd, tmp->name, env);
// 		// }
// 		// else if (pid > 0)
// 		// {
// 		// 	close(fd[1]);
// 		// 	waitpid(pid, &status, 0);
// 		// 	if (WIFEXITED(status))
// 		// 		g_exit_status = WEXITSTATUS(status);
// 		// 	cmd->in = fd[0];
// 		// }
// 		tmp = tmp->next;
// 	}
// }

int	heredoc_checking(t_cmdl *cmd)
{
	t_redir	*tmp;

	if (!cmd->redir)
		return (0);
	tmp = cmd->redir;
	if (ft_strcmp("<<", tmp->type) == 0)
		return (1);
	return (0);
}

//not other cmd block
bool	pre_execv(t_book *record, t_cmdl *cmds)
{
	if (!cmds->next && builtin_checker(cmds->command[0]) && !cmds->redir)
	{
		executing(record, cmds);
		return (1);
	}
	if (pipe_creator(cmds))
		return (1);
	g_exit_status = 0;
	while (cmds)
	{
		if (heredoc_checking(cmds))
			heredoc_processing(record, cmds);
		if (g_exit_status == 1)
			return (1);
		cmds = cmds->next;
	}
	return (0);
}
