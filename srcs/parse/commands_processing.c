/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:46 by yichan            #+#    #+#             */
/*   Updated: 2023/07/27 12:45:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Clean the command and filename
 * 			
 * 
 * @param record 
 */
void	quote_handler(t_book *record)
{
	t_cmdl	*cmd;
	t_redir	*rdr;
	int		it;

	cmd = record->cmds;
	rdr = record->cmds->redir;
	while (cmd)
	{
		if (cmd->command)
		{
			it = 0;
			while (cmd->command[it])
			{
				cmd->command[it] = ms_quotetrim(cmd->command[it]);
				it++;
			}
		}
		while (rdr)
		{
			rdr->name = ms_quotetrim(rdr->name);
			rdr = rdr->next;
		}
		cmd = cmd->next;
	}
}

//parser
void	ms_cmds(t_book *record)
{
	t_token	*tmp;
	t_token	*cmd_begin;

	if (record->args == NULL)
		return ;
	tmp = record->args;
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
	quote_handler(record);
}

// t_cmdl	*(commands_processing)(t_book *record)
// {
// 	t_token	*tmp;
// 	t_token	*cmd_begin;

// 	if (record->args == NULL)
// 		return (NULL);
// 	tmp = record->args;
// 	cmd_begin = tmp;
// 	if ((ft_strcmp(tmp->entity, "|")) == 0)
// 		tmp = tmp->next;
// 	while (tmp)
// 	{
// 		if ((ft_strcmp(tmp->entity, "|")) == 0)
// 		{
// 			cmds_lstadd_back(&record->cmds, cmds_lstnew(cmd_begin));
// 			cmd_begin = tmp->next;
// 		}
// 		tmp = tmp->next;
// 	}
// 	cmds_lstadd_back(&record->cmds, cmds_lstnew(cmd_begin));
// 	quote_handler(record);
// 	return (record->cmds);
// }
