/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/04/27 00:40:59 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		record->input = readline(BEGIN(1,31)"./minishell>$ "CLOSE);
		if (record->input == NULL)
			exit(exit_status) ;
		ms_token(record);
		ms_lexer(record);
		// printf("strqwe :%s\n", ((t_token *)(record->token->content))->entity);
		free(record->input);
		record->input = NULL;
		ms_tokenlclear(&(record->token), free);
		// liberator
	}
	return (0);
}
