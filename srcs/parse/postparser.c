/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quotetrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:05 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 11:05:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*is_slash(char *input, int *it)
// {
// 	char	*tmp_1;
// 	char	*tmp_2;

// 	tmp_1 = ft_substr(input, 0, *it);
// 	tmp_2 = ft_strdup(input + *it + 1);
// 	ft_free(input);
// 	input = NULL;
// 	input = ft_strjoin(tmp_1, tmp_2);
// 	ft_free(tmp_1);
// 	ft_free(tmp_2);
// 	(*it)++;
// 	return (input);
// }

/**
 * @brief 	Handle all the quote(removal) and
 * 			do the expander(is_dollar/key_handler)
 * 
 * @param input 
 * @param env 
 * @return char* 
 */
// "", '', \, $, ;, |, >, >>, <, ' *space* '
char	*ms_quotetrim(char *input)
{
	int		i;
	int		j;
	char	*ret;
	char	anchor;

	i = 0;
	j = 0;
	ret = ft_calloc(sizeof(char) * (ft_strlen(input) +1));
	while (input[i])
	{
		if (input[i] && ft_strchr("\'\"", input[i]))
		{
			anchor = input[i];
			i++;
			while (input[i] && input[i] != anchor)
				ret[j++] = input[i++];
			i++;
		}
		else if (input[i] && !ft_strchr("\'\"", input[i]))
			ret[j++] = input[i++];
	}
	ft_free(input);
	return (ret);
}

// char	*ms_quotetrim(char *input)
// {
// 	int		i;
// 	int		j;
// 	char	*ret;

// 	i = 0;
// 	j = 0;
// 	ret = ft_calloc(sizeof(char) * (ft_strlen(input) +1));
// 	printf("check: input post: %s\n", input);
// 	while (input[i])
// 	{
// 		if (input[i] && input[i] == '\'')
// 		{
// 			i++;
// 			while (input[i] && input[i] != '\'' )
// 				ret[j++] = input[i++];
// 			i++;
// 		}
// 		else if (input[i] && input[i] == '\"')
// 		{
// 			i++;
// 			while (input[i] && input[i] != '\"')
// 				ret[j++] = input[i++];
// 			i++;
// 		}
// 		else if (input[i] && !ft_strchr("\'\"", input[i]))
// 			ret[j++] = input[i++];
// 	}
// 	ft_free(input);
// 	return (ret);
// }