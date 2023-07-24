/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/07/19 01:18:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		// printf("Loop\n");
		sigs_interactive_shell(&record->termios_current);
		record->input = readline("minishell>$ ");
		// usleep(500);
		// if (*record->input == '\n')
			// sigs_interactive_shell();
			// sigs_non_interactive_shell();
		// g_exit_status = 0;
		if (record->input == NULL)
			exit(g_exit_status);
		if (*record->input)
			add_history(record->input);
		// if (*record->input)
		// 	add_history(record->input);
		// printf(RED"pass\n"DEFAULT);
		if (validator(record->input) == 0)
		{
			ms_token(record);
			// free(record->input);
			// record->input = NULL;
			// ms_lexer(record);
			// if (record->cmds)
			// 	ms_cmds(record);//parser?
			// record->
			// printf("check: cmd: %s", record->cmds->)
			ms_cmds(record);//parser?
		}
		free(record->input);
		record->input = NULL;
		sigs_non_interactive_shell();
		if (record->cmds)
			execute_cmds(record, record->cmds);
		// execute_cmds(record, record->cmds);
		// printf("strqwe :%s\n", ((t_token *)(record->token->content))->entity);
		free(record->input);
		record->input = 0;
		cleaner(record);
		rl_replace_line("", 0);
	}
	cleaner(record);
	return (0);
}
