/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:12:59 by yichan            #+#    #+#             */
/*   Updated: 2023/06/30 15:47:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_heredoc(t_cmdl *cmd, char *stop)
{
	char	*input;

	while (1)
	{
		// void	sig_non_interactive_ctrl_c(int sig)
		// sigs_non_interactive_shell();
		input = readline("> ");
		if (input == NULL || !ft_strncmp(input, stop, ft_strlen(stop) + 1))
			break ;
		ft_putendl_fd(input, cmd->out);
		free(input);
	}
	close(cmd->out);
	exit(0);
}

void	heredoc_processing(t_cmdl *cmd)
{
	int		fd[2];
	int		pid;
	t_redir	*tmp;
	// sigset_t signalSet;

	tmp =  cmd->redir;
	// printf("checking heredoc execute 1 \n");
	while (tmp)
	{
		// printf("checking heredoc execute 2 \n");
		if (pipe(fd) < 0)
		{
			perror("Error");
			g_exit_status = 1;
			exit (g_exit_status);
		// 	printf("checking heredoc execute 3 \n");
		}
		pid = fork();
		sigs_non_interactive_shell();
		if (pid == 0)
		{
			// printf("fork2: \n");
			// sigs_non_interactive_shell();
			// signal(SIGINT, SIG_IGN);
			// sigs_interactive_shell();
			// sigemptyset(&signalSet);
			signal(SIGINT, SIG_DFL);
			// sigs_non_interactive_shell();
			close(fd[0]);
			cmd->out = fd[1];
			signal(SIGQUIT, SIG_IGN);
			execute_heredoc(cmd, tmp->name);
			// printf("checking heredoc execute 4 \n");
		}
		else
		{
			close(fd[1]);
			waitpid(pid, NULL, 0);
			cmd->in = fd[0];
			// printf("checking heredoc execute 5 \n");
		}
		tmp = tmp->next;
	}
}

int	heredoc_checking(t_cmdl *cmd)
{
	t_redir	*tmp;

	if (!cmd->redir)
		return (0);
	tmp = cmd->redir;
	// ft_putnbr_fd(tmp->type, 2);
	// ft_putendl_fd("->type value", 2);
	if (ft_strcmp("<<", tmp->type) == 0)
		return (1);
	// printf
	// if (tmp->type == 10)
	// {
	// 	printf("return heredoc checking  here\n");
	// 	return (1);
	// }
	// if (tmp->type == DLEFT) // <<
	// 	return (1); // return to execute here_doc
	// printf(RED"return here checking with error checking6\n");
	return (0);
}
