/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:12:59 by yichan            #+#    #+#             */
/*   Updated: 2023/07/06 15:38:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_heredoc(t_cmdl *cmd, char *stop)
{
	char	*input;
	char	*buffer;
	// char 	*clear_sequence;

	buffer = malloc(sizeof(char *) * 1024);
	while (1)
	{
		input = readline("> ");
		// if (input == NULL)
		// {
		// 	// // tgetent(buffer, "> ");
		// 	// tgetent(buffer, input);
		// 	// // clear_sequence = tgetstr("rmso", &buffer);
		// 	// clear_sequence = tgetstr("rmso", NULL);
		// 	// tputs(clear_sequence, 1, putchar);
		// 	// if (input == NULL) 
		// 	// {
		// 	// 	printf(stderr, "Terminal does not support clear screen capability.\n");
		// 	// 	exit(1);
		// 	// }
		// 	cursor_plc(input);
		// 	break ;
		// }

		if (input == NULL || !ft_strncmp(input, stop, ft_strlen(stop) +1))
			break ;
		free(input);
	}
	close(cmd->out);
	exit(g_exit_status);
}

// void	heredoc_processing(t_cmdl *cmd)
// {
// 	int		fd[2];
// 	int		pid;
// 	t_redir	*tmp;
// 	int		status;

// 	tmp =  cmd->redir;
// 	// printf(RED"tmp->name : %s\n"DEFAULT, tmp->name);
// 	// printf(RED"tmp->type : %s\n"DEFAULT, tmp->type);
// 	while (tmp && ft_strcmp("<<", tmp->type) == 0)
// 	{
// 		// printf("type:%s name:%s\n ", tmp->type, tmp->name);
// 		// printf("next reidr type: %s & name: %s\n ", tmp->next->tmakype, tmp->next->name);
// 		if (pipe(fd) < 0)
// 		{
// 			perror("Error");
// 			g_exit_status = 1;
// 			break ;
// 			// exit (g_exit_status);
// 		}
// 		pid = fork();
// 		// signal (SIGINT, sig_interrupt_here);
// 		if (pid == 0)
// 		{
// 			signal (SIGINT, sig_interrupt_here);
// 			// sigs_non_interactive_shell();
// 			// signal(SIGINT, SIG_DFL);
// 			signal(SIGTERM, SIG_DFL);
// 			// signal(SIGINT, sig_non_interactive_ctrl_c);
// 			close(fd[0]);
// 			cmd->out = fd[1];
			
// 			execute_heredoc(cmd, tmp->name);
// 			// printf("g_exit_status: %d \n", g_exit_status);
// 		}
// 		else if (pid>0)
// 		{
// 			close(fd[1]);
// 			// signal (SIGINT, sig_interrupt_here);
// 			// signal(SIGINT, SIG_IGN);
// 			waitpid(pid, &status, 0);
// 			if (WIFEXITED(status)) 
// 			{
// 				// Child process terminated normally
// 				g_exit_status = WEXITSTATUS(status);
// 				// printf("Child process exited with status: %d\n", g_exit_status);
// 			} 
// 			// else if (WIFSIGNALED(status)) 
// 			// {
// 			// 	// Child process terminated due to a signal
// 			// 	int signal_number = WTERMSIG(status);
// 			// 	printf("Child process terminated by signal: %d\n", signal_number);
// 			// }
// 			// printf("g_exit_status: %d \n", g_exit_status);
// 			cmd->in = fd[0];
// 			if (g_exit_status == 1)
// 				break ;
// 		}
// 		tmp = tmp->next;
// 		// printf("end of loop \n");
// 	}
// }

void	heredoc_processing(t_cmdl *cmd)
{
	int		fd[2];
	int		pid;
	t_redir	*tmp;
	int		status;

	tmp =  cmd->redir;
	// printf(RED"tmp->name : %s\n"DEFAULT, tmp->name);
	// printf(RED"tmp->type : %s\n"DEFAULT, tmp->type);
	while (tmp && ft_strcmp("<<", tmp->type) == 0)
	{
		// printf("type:%s name:%s\n ", tmp->type, tmp->name);
		// printf("next reidr type: %s & name: %s\n ", tmp->next->tmakype, tmp->next->name);
		if (pipe(fd) < 0)
		{
			perror("Error");
			g_exit_status = 1;
			break ;
			// exit (g_exit_status);
		}
		pid = fork();
		// signal (SIGINT, sig_interrupt_here);
		if (pid == 0)
		{
			signal (SIGINT, sig_interrupt_here);
			// sigs_non_interactive_shell();
			// signal(SIGINT, SIG_DFL);
			signal(SIGTERM, SIG_DFL);
			// signal(SIGINT, sig_non_interactive_ctrl_c);
			close(fd[0]);
			cmd->out = fd[1];
			
			execute_heredoc(cmd, tmp->name);
			// printf("g_exit_status: %d \n", g_exit_status);
		}
		else if (pid>0)
		{
			close(fd[1]);
			// signal (SIGINT, sig_interrupt_here);
			// signal(SIGINT, SIG_IGN);
			waitpid(pid, &status, 0);
			if (WIFEXITED(status)) 
			{
				// Child process terminated normally
				g_exit_status = WEXITSTATUS(status);
				// printf("Child process exited with status: %d\n", g_exit_status);
			} 
			// else if (WIFSIGNALED(status)) 
			// {
			// 	// Child process terminated due to a signal
			// 	int signal_number = WTERMSIG(status);
			// 	printf("Child process terminated by signal: %d\n", signal_number);
			// }
			// printf("g_exit_status: %d \n", g_exit_status);
			cmd->in = fd[0];
			if (g_exit_status == 1)
				break ;
		}
		tmp = tmp->next;
		// printf("end of loop \n");
	}
}

// void	heredoc_processing(t_cmdl *cmd)
// {
// 	int		fd[2];
// 	// int		pid;
// 	t_redir	*tmp;

// 	tmp =  cmd->redir;
// 	while (tmp)
// 	{

// 		// sigs_non_interactive_shell();
// 		signal(SIGINT, SIG_DFL);
// 		cmd->in = fd[0];
// 		cmd->out = fd[1];
// 		execute_heredoc(cmd, tmp->name);
// 		close(fd[0]);

// 		close(fd[1]);
// 		// waitpid(pid, NULL, 0);
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

// void	heredoc_evaluation(t_cmdl *cmds)
// {
// 	while (cmds)
// 	{
// 		if (heredoc_checking(cmds))
// 		{
			
// 		}
// 	}
// }