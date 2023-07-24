/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:28 by yichan            #+#    #+#             */
/*   Updated: 2023/07/23 02:36:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pass_whitespaces(char *input, int it)
{
	if (input[it] == '\0')
		return (it);
	while (input[it] && ft_strchr("\t ", input[it]))
		it++;
	return (it);
}

int	opener(char *path, char flag)
{
	int	fd;

	fd = -1;
	if (flag == 'I')
		fd = open(path, O_RDONLY);
	else if (flag == 'O')
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (flag == 'A')
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		print_msg(1, strerror(errno), 1);
		g_exit_status = 1;
		exit(g_exit_status);
	}
	return (fd);
}

void	fd_opening(t_cmdl *cmds)
{
	t_redir	*tmp;
	int		it;

	if (cmds == NULL)
		return ;
	it = 0;
	tmp = cmds->redir;
	while (tmp)
	{
		if (ft_strcmp("<", tmp->type) == 0)
			cmds->in = opener(tmp->name, 'I');
		if (ft_strcmp(">", tmp->type) == 0)
			cmds->out = opener(tmp->name, 'O');
		if (ft_strcmp(">>", tmp->type) == 0)
			cmds->out = opener(tmp->name, 'A');
		tmp = tmp->next;
		it++;
	}
}
