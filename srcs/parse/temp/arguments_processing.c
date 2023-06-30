/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:37 by yichan            #+#    #+#             */
/*   Updated: 2023/06/26 17:51:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	find_end(char *input, int it, int *flag)
// {
// 	char	quote;

// 	while (input[it])
// 	{
// 		if (input[it] == '\'' || input[it] == '\"')
// 		{
// 			quote = input[it];
// 			it++;
// 			while (input[it] && input[it] != quote)
// 				it++;
// 		}
// 		if (ft_strchr(" \t<|>", input[it]))
// 		{
// 			if (ft_strchr("<|>", input[it]))
// 				*flag = 1;
// 			if (ft_strchr("<>", input[it]) && ft_strchr("<>", input[it + 1]))
// 				*flag = 2;
// //			it = pass_whitespaces(input, it);
// 			return (it);
// 		}
// 		it++;
// 	}
// 	return (it);
// }

// void	split_input(char *input, t_token **args, t_book *mini)
// {
// 	int		it;
// 	int		begin;
// 	int		end;
// 	int		flag;
// 	char	*tmp;

// 	it = 0;
// 	flag = 0;
// 	while (input[it] != '\0')
// 	{
// 		it = pass_whitespaces(input, it);
// 		begin = it;
// 		if (input[it] == '\0')
// 			return ;
// 		end = find_end(input, it, &flag);
// 		it = end;
// 		it = pass_whitespaces(input, it);
// 		if (flag != 0)
// 		{
// 			tmp = ft_substr(input, begin, end - begin);
// 			if (ft_strcmp(tmp, "\0"))
// 				args_lstadd_back(args, args_lstnew(tmp, mini));
// 			else
// 				free(tmp);
// 			args_lstadd_back(args, \
// 			args_lstnew(ft_substr(input, end, flag), mini));
// 			it += flag;
// 			flag = 0;
// 		}
// 		else
// 			args_lstadd_back(args, \
// 			args_lstnew(ft_substr(input, begin, end - begin), mini));
// 	}
// }

// t_token	*arguments_processing(t_book *mini)
// {
// 	split_input(mini->input, &(mini->args), mini);
// 	set_redirect(mini->args);
// 	return (mini->args);
// }
