/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:46 by yichan            #+#    #+#             */
/*   Updated: 2023/06/28 23:08:58 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Clean the command and filename
 * 			
 * 
 * @param mini 
 */
void	clean_cmd_and_filename(t_book *mini)
{
	t_cmdl	*cmd;
	t_redir	*rdr;
	int		it;

	cmd = mini->cmds;
	rdr = mini->cmds->redir;
	while (cmd)
	{
		if (cmd->command)
		{
			it = 0;
			while (cmd->command[it])
			{
				cmd->command[it] = postparser(cmd->command[it], mini->env);
				it++;
			}
		}
		while (rdr)
		{
			rdr->name = postparser(rdr->name, mini->env);
			rdr = rdr->next;
		}
		cmd = cmd->next;
	}
}

void	ms_cmds(t_book *record)
{
	t_token	*tmp;
	t_token	*cmd_begin;

	if (record->args == NULL)
		return ;
	tmp = record->args;
	// printf("%s\n", tmp->entity);
	// printf("check: args: %s\n", tmp->next->entity);
	cmd_begin = tmp;
	if ((ft_strcmp(tmp->entity, "|")) == 0)
		tmp = tmp->next;
	while (tmp)
	{
		if ((ft_strcmp(tmp->entity, "|")) == 0)
		{
			cmds_lstadd_back(&record->cmds, cmds_lstnew(cmd_begin));
			cmd_begin = tmp->next;
		}
		tmp = tmp->next;
	}
	cmds_lstadd_back(&record->cmds, cmds_lstnew(cmd_begin));
	// printf("rraedefasdfsdfa%s\n", record->cmds->command[0]);
	// printf("cmds: %s\n", record->cmds->command[1]);
	clean_cmd_and_filename(record);
}

// t_cmdl	*(commands_processing)(t_book *mini)
// {
// 	t_token	*tmp;
// 	t_token	*cmd_begin;

// 	if (mini->args == NULL)
// 		return (NULL);
// 	tmp = mini->args;
// 	cmd_begin = tmp;
// 	if ((ft_strcmp(tmp->entity, "|")) == 0)
// 		tmp = tmp->next;
// 	while (tmp)
// 	{
// 		if ((ft_strcmp(tmp->entity, "|")) == 0)
// 		{
// 			cmds_lstadd_back(&mini->cmds, cmds_lstnew(cmd_begin));
// 			cmd_begin = tmp->next;
// 		}
// 		tmp = tmp->next;
// 	}
// 	cmds_lstadd_back(&mini->cmds, cmds_lstnew(cmd_begin));
// 	clean_cmd_and_filename(mini);
// 	return (mini->cmds);
// }
