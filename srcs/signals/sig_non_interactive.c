/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_non_interactive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:58:54 by yichan            #+#    #+#             */
/*   Updated: 2023/07/02 00:30:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_non_interactive_quit(int sig)
{
	char	*nbr;

	ft_putstr_fd("Quit: \n", STDERR_FILENO);
	// fflush(0);
	// printf("Quit: \n");
	nbr = ft_itoa(sig);
	ft_putendl_fd(nbr, STDERR_FILENO);
	free(nbr);
	// nbr = NULL;
	g_exit_status = 131;
	// execve();
	// exit(g_exit_status);
}

void	sig_non_interactive_ctrl_c(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 2);

	// rl_replace_line("\n", 0);
	// rl_on_new_line();
	// rl_redisplay();
	// rl_clear_history();
	// printf("hereout\n");
	g_exit_status = 130;
	// exit(130);
}

// void	sigs_non_interactive_shell(void)
// {
// 	// sig_ign();
// 	signal(SIGTERM, SIG_IGN);
// 	signal(SIGINT, sig_non_interactive_ctrl_c);
// 	// signal(SIGQUIT, sig_non_interactive_quit);
// 	signal(SIGQUIT, SIG_IGN);
// }

// void	sigs_non_interactive_shell(void)
// {
// 	// sig_ign();
// 	signal(SIGTERM, SIG_DFL);
// 	signal(SIGINT, SIG_DFL);
// 	signal(SIGQUIT, SIG_IGN);
// }

// void	sigs_non_interactive_shell(void)
// {
// 	struct termios	termios_current;

// 	if (tcgetattr(STDIN_FILENO, &termios_current) == -1)
// 	{
// 		perror("Tcgetattr failed\n");
// 		exit(errno);
// 	}
// 	termios_current.c_lflag &= ~ECHOCTL;
// 	if (tcsetattr(STDIN_FILENO, TCSANOW, &termios_current) == -1)
// 	{
// 		perror("Tcsetattr failed\n");
// 		exit(errno);
// 	}
// 	// signal(SIGTERM, SIG_IGN);
// 	// signal(SIGINT, sig_non_interactive_ctrl_c);
// 	// signal(SIGQUIT, sig_non_interactive_quit);
// 	// signal(SIGINT, sig_non_interactive_quit);
// 	// signal(SIGQUIT, sig_non_interactive_quit);
// 	// signal(SIGQUIT, SIG_IGN);
// 	signal(SIGTERM, SIG_DFL);
// 	signal(SIGINT, sig_non_interactive_ctrl_c);
// 	// signal(SIGQUIT, SIG_IGN);
// }

void	sigs_non_interactive_shell(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, sig_non_interactive_ctrl_c);
}
