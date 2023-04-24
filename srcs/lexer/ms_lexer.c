/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:57:02 by yichan            #+#    #+#             */
/*   Updated: 2023/04/25 02:17:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_lexer(t_book *record)
{
	t_token			*token_itr;
	// t_token			*token_ptr;
	char			*check;
	const t_token	arr[] = {{.entity = "|", .type = PIPE},
	{.entity = "?", .type = QUERY}, {.entity = "$", .type = DOLLAR},
	{.entity = "<", .type = LEFT}, {.entity = ">", .type = RIGHT},
	{.entity = "<<", .type = DLEFT}, {.entity = ">>", .type = DRIGHT}};
	int				i;
	token_itr = record->token;
	while (token_itr)
	{
		i = -1;
		check = token_itr->entity;
		token_itr->type = LITERAL;
		while (++i < (int)(sizeof(arr) / sizeof(arr[0])))
		{
			if ((ft_strcmp(arr[i].entity, check)) == 0)
				token_itr->type = arr[i].type;
		}
		printf("token_ptr: %s type: %d \n", token_itr->entity, token_itr->type);
		token_itr = token_itr->next;
	}
	return (0);
}
		// if (ft_strcmp("|", check))
		// 	token_ptr->type = PIPE;
		// else if (ft_strcmp("?", check))
		// 	token_ptr->type = QUERY;
		// else if (ft_strcmp("$", check))
		// 	token_ptr->type = DOLLAR;
		// else if (ft_strcmp("<", check))
		// 	token_ptr->type = LEFT;
		// else if (ft_strcmp(">", check))
		// 	token_ptr->type = RIGHT;
		// else
		// 	token_ptr->type = LITERAL;