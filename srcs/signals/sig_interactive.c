/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_interactive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:30:47 by yichan            #+#    #+#             */
/*   Updated: 2023/07/02 19:27:12 by yichan           ###   ########.fr       */
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
	// write (STDERR_FILENO, "\n", 1);
	ft_putstr_fd("\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 1;
	// exit(g_exit_status);
}

void	sig_interrupt_here(int sig)
{
	if (sig != SIGINT)
		return ;
	// printf("interrupt\n");
	// write (STDERR_FILENO, "\n", 1);

	// ft_putstr_fd("\n", 2);
	rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();

	g_exit_status = 1;
	exit(1);
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

void	sig_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

void	sigs_interactive_shell(struct termios	*termios_current)
{
	// struct termios	termios_current;

	if (tcgetattr(STDIN_FILENO, termios_current) == -1)
	{
		perror("Tcgetattr failed1\n");
		exit(errno);
	}
	termios_current->c_lflag &= ~ECHOCTL;
	// termios_current.c_lflag |= ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, termios_current) == -1)
	{
		perror("Tcsetattr failed2\n");
		exit(errno);
	}
	// signal(SIGINT, &sig_interrupt);
	signal(SIGINT, &sig_interrupt);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}


void	reset_termios(struct termios	*termios_current)
{
	// struct termios	termios_current;
	// struct termios original_termios;

	// if (tcgetattr(STDIN_FILENO, &termios_current) == -1)
	// {
	// 	perror("Tcgetattr failed3\n");
	// 	exit(errno);
	// }
	// termios_current.c_lflag &= ~ECHOCTL;
	termios_current->c_lflag |= ECHOCTL;
	// tcgetattr(STDIN_FILENO, &termios_current);
	// // tcsetattr(STDIN_FILENO, TCSANOW, &termios_current)
	// // termios_current.c_lflag |= ECHOCTL;
	// // termios_current.c_lflag |= 256;
	
	// if (tcsetattr(STDIN_FILENO, TCSANOW, &termios_current) == -1)
	// {
	// 	// perror("Tcsetattr failed3\n");
	// 	exit(errno);
	// }
	tcsetattr(STDIN_FILENO, TCSANOW, termios_current);
// 	signal(SIGINT, &sig_interrupt);
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGTERM, SIG_IGN);
}
