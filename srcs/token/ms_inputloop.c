/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/08/04 02:38:50 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_history(t_book *record)
{
	if (*record->input)
	{
		add_history(record->input);
		ft_strcpy(record->history, record->input);
		return (1);
	}
	return (0);
}

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		sigs_interactive_shell(&record->termios_current);
		record->input = readline("minishell>$ ");
		if (record->input == NULL)
			exit(g_exit_status);
		if (*record->input)
			add_history(record->input);
		if (validator(record->input) == 0)
		{
			ms_token(record);
			ms_cmds(record);
		}
		ft_free(record->input);
		record->input = NULL;
		sigs_non_interactive_shell();
		if (record->cmds)
			execute_cmds(record, record->cmds);
		ft_free(record->input);
		record->input = 0;
		cleaner(record);
		rl_replace_line("", 0);
	}
	cleaner(record);
	return (0);
}
