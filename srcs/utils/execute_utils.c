/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:09 by yichan            #+#    #+#             */
/*   Updated: 2023/04/08 22:31:07 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_dup2(t_cmdl *cmds)
{
	if (cmds->in != STDIN_FILENO)
	{
		if (dup2(cmds->in, STDIN_FILENO) < 0)
			return (1);
		close(cmds->in);
	}
	if (cmds->out != STDOUT_FILENO)
	{
		if (dup2(cmds->out, STDOUT_FILENO) < 0)
			return (1);
		close(cmds->out);
	}
	return (0);
}
