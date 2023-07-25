/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_non_interactive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:58:54 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 09:41:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_non_interactive_quit(int sig)
{
	char	*nbr;

	ft_putstr_fd("Quit: \n", STDERR_FILENO);
	nbr = ft_itoa(sig);
	ft_putendl_fd(nbr, STDERR_FILENO);
	free(nbr);
	g_exit_status = 131;
}

void	sig_non_interactive_ctrl_c(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 2);
	g_exit_status = 130;
}

void	sigs_non_interactive_shell(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, sig_non_interactive_ctrl_c);
}
