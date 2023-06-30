/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_interactive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:30:47 by yichan            #+#    #+#             */
/*   Updated: 2023/06/29 17:52:45 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//interactive is tty; non interative is administrative and system maintenance
	// scripts ps kill by system

/**
 * @brief 	rl_replace_line() replaces the current line with the string pointed to by text.
 * 			rl_on_new_line() moves the cursor to the beginning of the next line.
 * 			rl_redisplay() redraws the current line.
 * 			* these will redraw the prompt and the current line.
 * @param sig 
 */
void	sig_interrupt(int sig)
{
	if (sig != SIGINT)
		return ;
	// printf("interrupt\n");
	write (STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 1;
	// exit(g_exit_status);
}

/**
 * @brief 	SIG_IGN == handler that ensure signal ignored
 * 			SIGTERM == signal termination (for exmaple the KILL command)
 * 			SIGQUIT(ctrl - \) == The SIGQUIT signal is similar to SIGINT,(stop signal)
 * 						except that it’s controlled by a different key—the QUIT character,
 * 			SIGINT	== The SIGINT signal is sent to a process by its controlling terminal when a user
 * 						wishes to interrupt the process. (ctrl+c)
 */
// void	sigs_interactive_shell(void)
// {
// 	sig_ign();
// 	signal(SIGINT, &sig_interrupt);
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGTERM, SIG_IGN);
// }

// void	sig_ignore(void)
// {
// 	signal(SIGINT, SIG_IGN);
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGTERM, SIG_IGN);
// 	// sigemptyset(SIGINT);
// 	// sigemptyset(SIGQUIT);
// 	// sigemptyset(SIGTERM);
// }

void	sigs_interactive_shell(void)
{
	struct termios	termios_current;

	if (tcgetattr(STDIN_FILENO, &termios_current) == -1)
	{
		perror("Tcgetattr failed\n");
		exit(errno);
	}
	termios_current.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termios_current) == -1)
	{
		perror("Tcsetattr failed\n");
		exit(errno);
	}
	signal(SIGINT, &sig_interrupt);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}
