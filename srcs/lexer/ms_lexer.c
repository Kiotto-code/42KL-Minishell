/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:57:02 by yichan            #+#    #+#             */
/*   Updated: 2023/07/02 17:53:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ms_lexer(t_book *record)
// {
// 	t_list			*token_itr;
// 	t_token			*token_ptr;
// 	char			*check;
// 	const t_token	arr[] = {{.entity = "|", .type = PIPE},
// 	{.entity = "?", .type = QUERY}, {.entity = "$", .type = DOLLAR},
// 	{.entity = "<", .type = LEFT}, {.entity = ">", .type = RIGHT}};
// 	int				i;

// 	token_itr = (t_list *)record->args;
// 	while (token_itr)
// 	{
// 		i = -1;
// 		token_ptr = ((t_token *)token_itr->content);
// 		check = token_ptr->entity;
// 		token_ptr->type = LITERAL;
// 		while (++i < (int)(sizeof(arr) / sizeof(arr[0])))
// 		{
// 			if ((ft_strcmp(arr[i].entity, check)) == 0)
// 				token_ptr->type = arr[i].type;
// 		}
// 		printf("token_ptr: %s \ntype: %d \n", token_ptr->entity, token_ptr->type);
// 		token_itr = token_itr->next;
// 	}
// 	return (0);
// }
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
	token_itr = record->args;
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
		// printf("token_ptr: %s", token_itr->entity);
		token_itr = token_itr->next;
	}
	// printf("token_ptr: %s type: %d \n", record->args->entity, record->args->type);
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