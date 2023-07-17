/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:05 by yichan            #+#    #+#             */
/*   Updated: 2023/07/10 23:08:33 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_slash(char *input, int *it)
{
	char	*tmp_1;
	char	*tmp_2;

	tmp_1 = ft_substr(input, 0, *it);
	tmp_2 = ft_strdup(input + *it + 1);
	free(input);
	input = NULL;
	input = ft_strjoin(tmp_1, tmp_2);
	free(tmp_1);
	free(tmp_2);
	(*it)++;
	return (input);
}

/**
 * @brief Handle all the quote(removal) and do the expander(is_dollar/key_handler)
 * 
 * @param input 
 * @param env 
 * @return char* 
 */
char	* postparser(char *input, t_env *env) // "", '', \, $, ;, |, >, >>, <, ' *space* '
{
	int	it;

	it = 0;
	printf("check: input post: %s\n", input);
	while (input[it])
	{
		if (input[it] == '\'')
			input = is_quote(input, &it);
		// if (input[it] == '\\')
		// 	input = is_slash(input, &it);
		if (input[it] == '\"')
			input = is_db_quote(input, &it, env);
		if (input[it] == '$')
			input = is_dollar(input, &it, env);
		it++;
	}
	printf("check: input post222: %s\n", input);
	return (input);
}
