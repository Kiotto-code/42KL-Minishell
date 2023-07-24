/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:46 by yichan            #+#    #+#             */
/*   Updated: 2023/07/22 18:45:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Clean the command and filename
 * 			
 * 
 * @param record 
 */
void	clean_cmd_and_filename(t_book *record)
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
				cmd->command[it] = postparser(cmd->command[it], record->env);
				// cmd->command[it] = ft_strdup(cmd->command[it]);
				it++;
			}
		}
		while (rdr)
		{
			rdr->name = postparser(rdr->name, record->env);
			// rdr->name = ft_strdup(cmd->command[it]);
			printf("type:%s name:%s\n", rdr->type, rdr->name);
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
			// printf(cmd_begin->)
			cmd_begin = tmp->next;
		}
		tmp = tmp->next;
	}
	cmds_lstadd_back(&record->cmds, cmds_lstnew(cmd_begin));
	ft_putstr_fd("check\n", 2);
	// printf("rraedefasdfsdfa%s\n", record->cmds->command[0]);
	// printf("cmds: %s\n", record->cmds->command[1]);
	clean_cmd_and_filename(record);
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
// 	clean_cmd_and_filename(record);
// 	return (record->cmds);
// }
