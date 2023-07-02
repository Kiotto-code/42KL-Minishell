/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:13:18 by yichan            #+#    #+#             */
/*   Updated: 2023/07/01 15:26:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_creation_error(t_cmdl *cmds)
{
	ft_putstr_fd("./minishell>$ ", STDERR_FILENO);
	ft_putendl_fd("fork: Resource temporarily unavailable", STDERR_FILENO);
	g_exit_status = 128;
	while (cmds->next)
	{
		if (!cmds->pipe_fd[0] || !cmds->pipe_fd[1])
			break ;
		close(cmds->pipe_fd[0]);
		close(cmds->pipe_fd[1]);
		cmds = cmds->next;
	}
	return (1);
}

int	pipe_creator(t_cmdl *cmds)
{
	t_cmdl	*begin;

	begin = cmds;
	while (cmds->next)
	{
		if (pipe(cmds->pipe_fd) < 0)
			return (pipe_creation_error(begin));
		cmds->out = cmds->pipe_fd[1];
		cmds->next->in = cmds->pipe_fd[0];
		cmds = cmds->next;
	}
	return (0);
}
